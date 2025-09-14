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

std::optional<questnav_protos_commands_ProtobufQuestNavCommand>
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
  return msg;
}

bool wpi::Protobuf<questnav::CommandStruct>::Pack(
    OutputStream& stream, const questnav_protos_commands_ProtobufQuestNavCommand& value) {
  return stream.Encode(value);
}