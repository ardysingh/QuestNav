/*
* QUESTNAV
  https://github.com/QuestNav
* Copyright (C) 2025 QuestNav
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the MIT License as published.
*/
#include <wpi/protobuf/ProtobufCallbacks.h>

#include "gg/questnav/questnav/protos/wpilib/CommandResponseProto.h"

using InputStream = wpi::ProtoInputStream<questnav::CommandResponseStruct>;
using OutputStream = wpi::ProtoOutputStream<questnav::CommandResponseStruct>;

std::optional<questnav::CommandResponseStruct>
wpi::Protobuf<questnav::CommandResponseStruct>::Unpack(InputStream& istream) {
  questnav_protos_commands_ProtobufQuestNavCommandResponse msg;
  if (!istream.Decode(msg)) {
    return std::nullopt;
  }

  // ADS TBD: Populate a questnav::CommandResponseStruct from msg
  // return msg;
  return std::nullopt;
}

bool wpi::Protobuf<questnav::CommandResponseStruct>::Pack(
    OutputStream& ostream, const questnav::CommandResponseStruct& value) {
  // ADS TBD: Populate a questnav_protos_commands_ProtobufQuestNavCommandResponse from value
  questnav_protos_commands_ProtobufQuestNavCommandResponse msg {};
  return ostream.Encode(msg);
}