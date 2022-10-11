#include "pch.h"
#include <wiring_digital.h>

Beeper::Beeper(uint32_t Att) : AttachedPin(Att)
{
  pinMode(AttachedPin, OUTPUT);
}

void Beeper::Beep(uint32_t Freq, uint32_t Duration)
{
  tone(AttachedPin, Freq, Duration);
}

void Beeper::Stop()
{
  noTone(AttachedPin);
}