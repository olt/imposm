// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "imposm_internal.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace imposm {
namespace cache {
namespace internal {

namespace {

const ::google::protobuf::Descriptor* DeltaNodes_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DeltaNodes_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_imposm_5finternal_2eproto() {
  protobuf_AddDesc_imposm_5finternal_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "imposm_internal.proto");
  GOOGLE_CHECK(file != NULL);
  DeltaNodes_descriptor_ = file->message_type(0);
  static const int DeltaNodes_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeltaNodes, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeltaNodes, lat_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeltaNodes, lon_),
  };
  DeltaNodes_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DeltaNodes_descriptor_,
      DeltaNodes::default_instance_,
      DeltaNodes_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeltaNodes, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeltaNodes, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DeltaNodes));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_imposm_5finternal_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DeltaNodes_descriptor_, &DeltaNodes::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_imposm_5finternal_2eproto() {
  delete DeltaNodes::default_instance_;
  delete DeltaNodes_reflection_;
}

void protobuf_AddDesc_imposm_5finternal_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025imposm_internal.proto\022\025imposm.cache.in"
    "ternal\">\n\nDeltaNodes\022\016\n\002id\030\001 \003(\022B\002\020\001\022\017\n\003"
    "lat\030\002 \003(\021B\002\020\001\022\017\n\003lon\030\003 \003(\021B\002\020\001", 110);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "imposm_internal.proto", &protobuf_RegisterTypes);
  DeltaNodes::default_instance_ = new DeltaNodes();
  DeltaNodes::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_imposm_5finternal_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_imposm_5finternal_2eproto {
  StaticDescriptorInitializer_imposm_5finternal_2eproto() {
    protobuf_AddDesc_imposm_5finternal_2eproto();
  }
} static_descriptor_initializer_imposm_5finternal_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int DeltaNodes::kIdFieldNumber;
const int DeltaNodes::kLatFieldNumber;
const int DeltaNodes::kLonFieldNumber;
#endif  // !_MSC_VER

DeltaNodes::DeltaNodes()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DeltaNodes::InitAsDefaultInstance() {
}

DeltaNodes::DeltaNodes(const DeltaNodes& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DeltaNodes::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DeltaNodes::~DeltaNodes() {
  SharedDtor();
}

void DeltaNodes::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DeltaNodes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DeltaNodes::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DeltaNodes_descriptor_;
}

const DeltaNodes& DeltaNodes::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_imposm_5finternal_2eproto();  return *default_instance_;
}

DeltaNodes* DeltaNodes::default_instance_ = NULL;

DeltaNodes* DeltaNodes::New() const {
  return new DeltaNodes;
}

void DeltaNodes::Clear() {
  id_.Clear();
  lat_.Clear();
  lon_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DeltaNodes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated sint64 id = 1 [packed = true];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 input, this->mutable_id())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 1, 10, input, this->mutable_id())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_lat;
        break;
      }
      
      // repeated sint32 lat = 2 [packed = true];
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_lat:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, this->mutable_lat())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 1, 18, input, this->mutable_lat())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_lon;
        break;
      }
      
      // repeated sint32 lon = 3 [packed = true];
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_lon:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, this->mutable_lon())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 1, 26, input, this->mutable_lon())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DeltaNodes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated sint64 id = 1 [packed = true];
  if (this->id_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(1, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_id_cached_byte_size_);
  }
  for (int i = 0; i < this->id_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt64NoTag(
      this->id(i), output);
  }
  
  // repeated sint32 lat = 2 [packed = true];
  if (this->lat_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_lat_cached_byte_size_);
  }
  for (int i = 0; i < this->lat_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32NoTag(
      this->lat(i), output);
  }
  
  // repeated sint32 lon = 3 [packed = true];
  if (this->lon_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_lon_cached_byte_size_);
  }
  for (int i = 0; i < this->lon_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32NoTag(
      this->lon(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DeltaNodes::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated sint64 id = 1 [packed = true];
  if (this->id_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      1,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _id_cached_byte_size_, target);
  }
  for (int i = 0; i < this->id_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteSInt64NoTagToArray(this->id(i), target);
  }
  
  // repeated sint32 lat = 2 [packed = true];
  if (this->lat_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _lat_cached_byte_size_, target);
  }
  for (int i = 0; i < this->lat_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteSInt32NoTagToArray(this->lat(i), target);
  }
  
  // repeated sint32 lon = 3 [packed = true];
  if (this->lon_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _lon_cached_byte_size_, target);
  }
  for (int i = 0; i < this->lon_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteSInt32NoTagToArray(this->lon(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DeltaNodes::ByteSize() const {
  int total_size = 0;
  
  // repeated sint64 id = 1 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->id_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        SInt64Size(this->id(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _id_cached_byte_size_ = data_size;
    total_size += data_size;
  }
  
  // repeated sint32 lat = 2 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->lat_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        SInt32Size(this->lat(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _lat_cached_byte_size_ = data_size;
    total_size += data_size;
  }
  
  // repeated sint32 lon = 3 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->lon_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        SInt32Size(this->lon(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _lon_cached_byte_size_ = data_size;
    total_size += data_size;
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DeltaNodes::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DeltaNodes* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DeltaNodes*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DeltaNodes::MergeFrom(const DeltaNodes& from) {
  GOOGLE_CHECK_NE(&from, this);
  id_.MergeFrom(from.id_);
  lat_.MergeFrom(from.lat_);
  lon_.MergeFrom(from.lon_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DeltaNodes::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DeltaNodes::CopyFrom(const DeltaNodes& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DeltaNodes::IsInitialized() const {
  
  return true;
}

void DeltaNodes::Swap(DeltaNodes* other) {
  if (other != this) {
    id_.Swap(&other->id_);
    lat_.Swap(&other->lat_);
    lon_.Swap(&other->lon_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DeltaNodes::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DeltaNodes_descriptor_;
  metadata.reflection = DeltaNodes_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace internal
}  // namespace cache
}  // namespace imposm

// @@protoc_insertion_point(global_scope)