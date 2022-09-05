#include "Linetracker.h"
#include "pch.h"
Linetracker::Linetracker(PinName Ach) : AttachedPin(Ach)
{
  pinMode(AttachedPin, INPUT);
}

bool Linetracker::OnLine()
{
  return digitalReadFast(AttachedPin) == HIGH;
}

bool Linetracker::operator==(Linetracker lt)
{
  return this->OnLine() == lt.OnLine();
}