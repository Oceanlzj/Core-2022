#include "LED.h"
LED::LED(PinName P) : Pin(P)
{
  pinMode(Pin, OUTPUT);
}

void LED::Off()
{
  digitalWriteFast(Pin, HIGH);
}

void LED::On()
{
  digitalWriteFast(Pin, LOW);
}

void LED::Toggle()
{
  digitalToggleFast(Pin);
}