#ifndef __SCANNER_H__
#define __SCANNER_H__
#include <HardwareSerial.h>
#include <PinNames.h>

class Scanner
{
private:
  HardwareSerial *SerialAttached;
  PinName TriggerPin;
public:
  Scanner(HardwareSerial *SerialAtt,  PinName TriPin);

  String Scan();
  void Reset();

};



#endif