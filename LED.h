#ifndef __LED_H__
#define __LED_H__
#include "PinNames.h"
#include "Arduino.h"
#include "wiring_digital.h"
class LED
{
private:
  PinName Pin;

public:
  LED(PinName P);


  void On();
  void Off();
  void Toggle();

};

#endif