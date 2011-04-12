from imposm.base import Node, Way, Relation

cdef extern from "Python.h":
    object PyString_FromStringAndSize(char *s, Py_ssize_t len)

cdef extern from "marshal.h":
    object PyMarshal_ReadObjectFromString(char *string, Py_ssize_t len)
    object PyMarshal_WriteObjectToString(object value, int version)

cdef extern from "tcutil.h":
    ctypedef int TCCMP()
    cdef int tccmpint32()
    cdef int tccmpint64()

cdef extern from "tcbdb.h":
    ctypedef enum:
        BDBFOPEN
        BDBFFATAL

    ctypedef enum:
        BDBOREADER = 1 << 0 # /* open as a reader */
        BDBOWRITER = 1 << 1 # /* open as a writer */
        BDBOCREAT = 1 << 2  # /* writer creating */
        BDBOTRUNC = 1 << 3  # /* writer truncating */
        BDBONOLCK = 1 << 4  # /* open without locking */
        BDBOLCKNB = 1 << 5  # /* lock without blocking */
        BDBOTSYNC = 1 << 6  # /* synchronize every transaction */

    ctypedef enum:
        BDBTLARGE = 1 << 0,  # /* use 64-bit bucket array */
        BDBTDEFLATE = 1 << 1 # /* compress each page with Deflate */
        BDBTBZIP = 1 << 2,   # /* compress each record with BZIP2 */
        BDBTTCBS = 1 << 3,   # /* compress each page with TCBS */
        BDBTEXCODEC = 1 << 4 # /* compress each record with outer functions */

    ctypedef void TCBDB
    ctypedef void BDBCUR

    TCBDB *tcbdbnew()
    void tcbdbdel(TCBDB *)
    int tcbdbecode(TCBDB *)

    bint tcbdbtune(TCBDB *db, int lmemb, int nmemb,
                   int bnum, int apow, int fpow, int opts)
    bint tcbdbsetcache(TCBDB *bdb, int lcnum, int ncnum)

    bint tcbdbsetcmpfunc(TCBDB *bdb, TCCMP cmp, void *cmpop)
    bint tcbdbsetmutex(TCBDB *bdb)

    bint tcbdbopen(TCBDB *, char *, int)
    bint tcbdbclose(TCBDB *) nogil
    bint tcbdbput(TCBDB *, void *, int, void *, int) nogil
    void *tcbdbget(TCBDB *, void *, int, int *) nogil
    void *tcbdbget3(TCBDB *bdb, void *kbuf, int ksiz, int *sp) nogil

    long tcbdbrnum(TCBDB *bdb)

    BDBCUR *tcbdbcurnew(TCBDB *bdb)
    void tcbdbcurdel(BDBCUR *cur)
    bint tcbdbcurfirst(BDBCUR *cur)
    bint tcbdbcurnext(BDBCUR *cur)
    void *tcbdbcurkey3(BDBCUR *cur, int *sp)
    void *tcbdbcurval3(BDBCUR *cur, int *sp)


DEF COORD_FACTOR = 23860929.422222223 # (2<<32)/360.0

cdef long _coord_to_long(double x) nogil:
    return <long>((x + 180.0) * COORD_FACTOR)

cdef double _long_to_coord(long x) nogil:
    return <double>((x / COORD_FACTOR) - 180.0)

ctypedef struct coord:
    long x
    long y

cdef inline coord coord_struct(double x, double y) nogil:
    cdef coord p
    p.x = _coord_to_long(x)
    p.y = _coord_to_long(y)
    return p

_modes = {
    'w': BDBOWRITER | BDBOCREAT,
    'r': BDBOREADER | BDBONOLCK,
}

cdef class BDB:
    cdef TCBDB *db
    cdef object filename
    cdef int _opened
    cdef BDBCUR *_cur
    def __cinit__(self, filename, mode='w', estimated_records=0):
        self.db = tcbdbnew()
        self._opened = 0

    def __init__(self, filename, mode='w', estimated_records=0):
        self.filename = filename
        self._tune_db(estimated_records)
        tcbdbsetcmpfunc(self.db, tccmpint64, NULL)
        if not tcbdbopen(self.db, filename, _modes[mode]):
            raise IOError
        self._opened = 1
    
    def _tune_db(self, estimated_records):
        if estimated_records:
            lmemb = 128 # default
            nmemb = -1
            fpow = 13 # 2^13 = 8196
            bnum = int((estimated_records*3)/lmemb)
            tcbdbtune(self.db, lmemb, nmemb, bnum, 5, fpow, BDBTLARGE | BDBTDEFLATE)
        else:
            tcbdbtune(self.db, -1, -1, -1, 5, 13, BDBTLARGE | BDBTDEFLATE)
    
    def get(self, long long osmid):
        """
        Return object with given id.
        Returns None if id is not stored.
        """
        cdef void *ret
        cdef int ret_size
        ret = tcbdbget3(self.db, <char *>&osmid, sizeof(long long), &ret_size)
        if not ret: return None
        return self._obj(osmid, PyMarshal_ReadObjectFromString(<char *>ret, ret_size))

    cdef object _obj(self, long long osmid, data):
        """
        Create an object from the id and unmarshaled data.
        Should be overridden by subclasses.
        """
        pass

    def __iter__(self):
        """
        Return an iterator over the database.
        Resets any existing iterator.
        """
        if self._cur:
            tcbdbcurdel(self._cur)
        self._cur = tcbdbcurnew(self.db)
        if not tcbdbcurfirst(self._cur):
            return iter([])
        return self

    def __contains__(self, long long osmid):
        cdef void *ret
        cdef int ret_size
        ret = tcbdbget3(self.db, <char *>&osmid, sizeof(long long), &ret_size);
        if ret:
            return 1
        else:
            return 0
    
    def __len__(self):
        return tcbdbrnum(self.db)
    
    def __next__(self):
        """
        Return next item as object.
        """
        cdef long long osmid

        if not self._cur: raise StopIteration

        osmid, data = self._get_cur()

        # advance cursor, set to NULL if at the end
        if tcbdbcurnext(self._cur) == 0:
            tcbdbcurdel(self._cur)
            self._cur = NULL
        
        # return objectified item
        return self._obj(osmid, data)

    cdef object _get_cur(self):
        """
        Return the current object at the current cursor position
        as a tuple of the id and the unmarshaled data.
        """
        cdef int size
        cdef void *ret
        ret = tcbdbcurkey3(self._cur, &size)
        osmid = (<long long *>ret)[0]
        ret = tcbdbcurval3(self._cur, &size)
        value = PyMarshal_ReadObjectFromString(<char *>ret, size)
        return osmid, value

    def close(self):
        if self._opened:
            tcbdbclose(self.db)
        self._opened = 0
    
    def __dealloc__(self):
        if self._opened:
            tcbdbclose(self.db)
        tcbdbdel(self.db)

cdef class CoordDB(BDB):
    def put(self, osmid, x, y):
        return self._put(osmid, x, y)
    
    def put_marshaled(self, osmid, x, y):
        return self._put(osmid, x, y)
    
    cdef bint _put(self, long long osmid, double x, double y) nogil:
        cdef coord p = coord_struct(x, y)
        return tcbdbput(self.db, <char *>&osmid, sizeof(long long), <char *>&p, sizeof(coord))

    def get(self, long long osmid):
        cdef coord *value
        cdef int ret_size
        value = <coord *>tcbdbget3(self.db, <char *>&osmid, sizeof(long long), &ret_size)
        if not value: return
        return _long_to_coord(value.x), _long_to_coord(value.y)

    def get_coords(self, refs):
        cdef coord *value
        cdef int ret_size
        cdef long long osmid
        coords = list()
        for osmid in refs:
            value = <coord *>tcbdbget3(self.db, <char *>&osmid, sizeof(long long), &ret_size)
            if not value: return
            coords.append((_long_to_coord(value.x), _long_to_coord(value.y)))
        
        return coords

    cdef object _get_cur(self):
        cdef int size
        cdef long long osmid
        cdef void *ret
        cdef coord *value
        ret = tcbdbcurkey3(self._cur, &size)
        osmid = (<long long *>ret)[0]
        value = <coord *>tcbdbcurval3(self._cur, &size)
        return osmid, (_long_to_coord(value.x), _long_to_coord(value.y))

    cdef object _obj(self, long long osmid, data):
        return osmid, data

cdef class NodeDB(BDB):
    def put(self, osmid, tags, pos):
        return self.put_marshaled(osmid, PyMarshal_WriteObjectToString((tags, pos), 2))
    
    def put_marshaled(self, long long osmid, data):
        return tcbdbput(self.db, <char *>&osmid, sizeof(long long), <char *>data, len(data))

    cdef object _obj(self, long long osmid, data):
        return Node(osmid, data[0], data[1])

cdef class RefTagDB(BDB):
    """
    Database for items with references and tags (i.e. ways/relations).
    """
    def put(self, osmid, tags, refs):
        return self.put_marshaled(osmid, PyMarshal_WriteObjectToString((tags, refs), 2))
    
    def put_marshaled(self, long long osmid, data):
        return tcbdbput(self.db, <char *>&osmid, sizeof(long long), <char *>data, len(data))

cdef class WayDB(RefTagDB):
    cdef object _obj(self, long long osmid, data):
        return Way(osmid, data[0], data[1])

cdef class RelationDB(RefTagDB):
    cdef object _obj(self, long long osmid, data):
        return Relation(osmid, data[0], data[1])