// Copyright (C) Martin Da Costa 2023 (martindc.merg@gmail.com)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include "Service.h"
#include "ConsumeOwnEventsService.h"
#include <vlcbdefs.hpp>

namespace VLCB {

class Configuration;

class EventConsumerService : public Service {
public:
  virtual void setController(Controller *cntrl) override;
  void setEventHandler(void (*fptr)(byte index, VlcbMessage *msg));
  virtual Processed handleMessage(unsigned int opc, VlcbMessage *msg) override;

  virtual byte getServiceID() override 
  {
    return SERVICE_ID_CONSUMER;
  }
  virtual byte getServiceVersionID() override 
  {
    return 1;
  }

private:
  Controller *controller;
  Configuration *module_config;  // Shortcut to reduce indirection code.
  void (*eventhandler)(byte index, VlcbMessage *msg) = nullptr;

  void processAccessoryEvent(VlcbMessage *msg, unsigned int nn, unsigned int en);
};

}  // VLCB
