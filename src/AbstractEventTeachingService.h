// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include "Service.h"

namespace VLCB 
{

struct VlcbMessage;

class AbstractEventTeachingService : public Service 
{
public:
  void setEventValidator(byte (*func)(int, int, byte, byte)) { validatorFunc = func; }

  virtual Data getServiceData() override;

  void enableLearn();
  void inhibitLearn();

protected:
  bool bLearn = false;
  byte (*validatorFunc)(int, int, byte, byte) = nullptr;
  unsigned int diagEventsTaught = 0;

  void handleMessage(const VlcbMessage *msg);
  
private:
  void handleLearnMode(const VlcbMessage *msg, unsigned int nn);
  void handleLearn(unsigned int nn);
  void handleUnlearnEvent(const VlcbMessage *msg, unsigned int nn);
  void handleUnlearn(unsigned int nn);
  void handleRequestEventCount(unsigned int nn);
  void handleReadEvents(unsigned int nn);
  void handleReadEventVariable(const VlcbMessage *msg, unsigned int nn);
  void handleClearEvents(unsigned int nn);
  void handleGetFreeEventSlots(unsigned int nn);
};

}  // VLCB
