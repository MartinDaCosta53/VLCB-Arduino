//  Copyright (C) Sven Rosvall (sven@rosvall.ie)
//  This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
//  Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
//  The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0

#pragma once

#include "AbstractEventTeachingService.h"

namespace VLCB
{

class EventSlotTeachingService : public AbstractEventTeachingService
{
public:
  virtual void process(const Action * action) override;
  virtual VlcbServiceTypes getServiceID() const override { return SERVICE_ID_TEACH; }
  virtual byte getServiceVersionID() const override { return 1; }

private:
  void handleMessage(const VlcbMessage *msg);
  void handleLearnEventIndex(const VlcbMessage *msg);
  void handleReadEventIndex(unsigned int nn, byte eventIndex);
};

}  // VLCB
