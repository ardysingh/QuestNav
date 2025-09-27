/*
* QUESTNAV
  https://github.com/QuestNav
* Copyright (C) 2025 QuestNav
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the MIT License as published.
*/
#include <wpi/protobuf/ProtobufCallbacks.h>

#include "gg/questnav/questnav/protos/wpilib/FrameDataProto.h"

using InputStream = wpi::ProtoInputStream<questnav::FrameDataStruct>;
using OutputStream = wpi::ProtoOutputStream<questnav::FrameDataStruct>;

std::optional<questnav::FrameDataStruct>
wpi::Protobuf<questnav::FrameDataStruct>::Unpack(InputStream& stream) {
  questnav_protos_data_ProtobufQuestNavFrameData  msg;
  if (!stream.Decode(msg)) {
    return std::nullopt;
  }

  // ADS TBD: Populate a questnav::FrameDataStruct from msg
  // return msg;
  // questnav::FrameDataStruct ret_val{};
  // frc::Pose2d msg_pose2d = static_cast<frc::Pose2d>(msg.pose2d());
  // nret_val.pose2d(msg_pose2d.X(), msg_pose2d.Y(), msg_pose2d.Rotation());
  // ret_val.frame_count = msg.frame_count;
  // ret_val.timestamp = msg.timestamp;

  return std::nullopt;
}

bool encode_pose2d_transaction_callback(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
  return true;
}

bool encode_pose2d_rotation_callback(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
  return true;
}

bool encode_pose2d_callback(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
    // The 'arg' pointer will be your custom data
    const frc::Pose2d* pose2d = reinterpret_cast<const frc::Pose2d*>(*arg);

    // First, encode the tag for the field
    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    // Then, encode the submessage
    _wpi_proto_ProtobufPose2d proto_item;
    proto_item.translation.funcs.encode = &encode_pose2d_transaction_callback;
    proto_item.translation.arg = (void*) &pose2d->Translation();

    proto_item.rotation.funcs.encode = &encode_pose2d_rotation_callback;
    proto_item.rotation.arg = (void*) &pose2d->Rotation();

    // stream->Encode(proto_item);
    if (!pb_encode_submessage(stream, proto_item.msg_descriptor(), &proto_item)) {
        return false;
    }
    return true;
}

bool wpi::Protobuf<questnav::FrameDataStruct>::Pack(
    OutputStream& ostream, const questnav::FrameDataStruct& value) {
  // ADS TBD: Populate a questnav_protos_data_ProtobufQuestNavFrameData from value
  questnav_protos_data_ProtobufQuestNavFrameData msg = questnav_protos_data_ProtobufQuestNavFrameData_init_default;

  msg.frame_count = value.frame_count;
  msg.timestamp = value.timestamp;
  msg.pose2d.funcs.encode = &encode_pose2d_callback;
  msg.pose2d.arg = (void *) &value.pose2d;

  return ostream.Encode(msg);
  // return pb_encode(&ostream, msg.msg_descriptor(), &msg);
}



