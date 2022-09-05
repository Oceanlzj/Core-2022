#include "pch.h"
#include <wiring_digital.h>

Beeper::Beeper(uint32_t Att) : AttachedPin(Att)
{
  pinMode(AttachedPin, OUTPUT);
   //analogWriteResolution()
}

void Beeper::Beep(uint32_t Freq)
{
  analogWriteFrequency(Freq);
  analogWrite(AttachedPin, 230);
}

void Beeper::Stop()
{
  analogWrite(AttachedPin, 0);
}