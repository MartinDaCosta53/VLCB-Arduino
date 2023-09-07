// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include "Service.h"

namespace VLCB {

class Configuration;

class EventProducerService : public Service {
public:
  virtual void setController(Controller *cntrl) override;
  virtual void process(byte num); 
  virtual Processed handleMessage(unsigned int opc, CANFrame *msg) override;

  virtual byte getServiceID() override 
  {
    return 5;
  }
  virtual byte getServiceVersionID() override 
  {
    return 1;
  }
  void begin();
  void sendEvent(bool state, byte index);
  void sendEvent(bool state, byte index, byte data1);
  void sendEvent(bool state, byte index, byte data1, byte data2);
  void sendEvent(bool state, byte index, byte data1, byte data2, byte data3);

private:
  Controller *controller;
  Configuration *module_config;  // Shortcut to reduce indirection code.
  void (*eventhandler)(byte index, CANFrame *msg);
 
  void setProducedEvents();
};

}  // VLCB