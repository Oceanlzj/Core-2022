#include "pch.h"
#include "ServoWithStep.h"

ServoWithStep::ServoWithStep(uint32_t Att, uint32_t init) : AttachedPin(Att)
{
}

void ServoWithStep::Init(int32_t init)
{
  this->attach(AttachedPin, 500, 2500, init);
}
void ServoWithStep::Setpos(uint16_t pos)
{
  this->writeMicroseconds(pos);
}

// setPos with step
void ServoWithStep::Setpos(uint16_t pos, uint16_t spd)
{
  int Current_Pos = readMicroseconds();
  if (pos > Current_Pos)
  {
    for (; Current_Pos < pos; Current_Pos += spd)
    {
      this->Setpos(Current_Pos);
      delay(spd / 2);
    }
  }
  else
  {
    for (; Current_Pos > pos; Current_Pos -= spd)
    {
      this->Setpos(Current_Pos);
      delay(spd / 2);
    }
  }
  this->Setpos(pos);
  Current_Pos = pos;
}

// operator= setpos
uint16_t ServoWithStep::operator=(uint16_t pos)
{
  this->writeMicroseconds(pos);
  return pos;
}