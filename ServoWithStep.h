#ifndef __SERVOWITHSTEP_H__
#define __SERVOWITHSTEP_H__
#include <Servo.h>

class ServoWithStep : public Servo
{
private:
  uint32_t AttachedPin;

public:
  ServoWithStep(uint32_t Att, uint32_t init = 1500);

  void Init(int32_t init = 1500);
  void Setpos(uint16_t pos);
  void Setpos(uint16_t pos, uint16_t spd);

  uint16_t operator=(uint16_t pos);
};

#endif