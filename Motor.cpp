#include "pch.h"
#include "Motor.h"

Motor::Motor(uint32_t STP, uint32_t DIR, uint32_t EN) : AccelStepper(AccelStepper::DRIVER, STP, DIR), Pin_STP(STP), Pin_DIR(DIR), Pin_EN(EN)
{
  pinMode(STP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  
}

void Motor::Enable()
{
  digitalWriteFast(digitalPinToPinName(Pin_EN), HIGH);
}

void Motor::Disable()
{
  digitalWriteFast(digitalPinToPinName(Pin_EN), LOW);
}
