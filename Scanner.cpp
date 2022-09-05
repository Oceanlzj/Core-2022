#include "pch.h"

Scanner::Scanner(HardwareSerial *SerialAtt, PinName TriPin) : SerialAttached(SerialAtt), TriggerPin(TriPin)
{
  pinMode(TriPin, OUTPUT);
}

String Scanner::Scan()
{
  String RecivedString = "";
  digitalWriteFast(TriggerPin, LOW);
  delay(10);
  while(SerialAttached->available() > 0)
  {
    RecivedString += (char)SerialAttached->read();
  }
  //Serial1.println(RecivedString);
  //digitalWriteFast(TriggerPin, HIGH);
  return RecivedString;

}

void Scanner::Reset()
{
  digitalWriteFast(TriggerPin, HIGH);
}