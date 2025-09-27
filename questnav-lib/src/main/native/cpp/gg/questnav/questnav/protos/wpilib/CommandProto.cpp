/*
* QUESTNAV
  https://github.com/QuestNav
* Copyright (C) 2025 QuestNav
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the MIT License as published.
*/
#include <wpi/protobuf/ProtobufCallbacks.h>

#include "gg/questnav/questnav/protos/wpilib/CommandProto.h"
#include "gg/questnav/questnav/struct/CommandStruct.h"

using InputStream = wpi::ProtoInputStream<questnav::CommandStruct>;
using OutputStream = wpi::ProtoOutputStream<questnav::CommandStruct>;

std::optional<questnav::CommandStruct>
wpi::Protobuf<questnav::CommandStruct>::Unpack(InputStream& stream) {
  wpi::UnpackCallback<questnav::CommandType> typ;

  questnav_protos_commands_ProtobufQuestNavCommand msg {};
  /*  
     .type = typ.Callback(),
     .command_id = 0,
     .payload = ""
    }
  */
  if (!stream.Decode(msg)) {
    return std::nullopt;
  }

  // ADS TBD: Populate a questnav::CommandStruct from msg
  // return msg;
  return std::nullopt;
}

bool wpi::Protobuf<questnav::CommandStruct>::Pack
(
    OutputStream& stream, const questnav::CommandStruct& value) {
  // ADS TBD: Populate a questnav_protos_commands_ProtobufQuestNavCommand from value
  questnav_protos_commands_ProtobufQuestNavCommand msg {};
  return stream.Encode(msg);
}