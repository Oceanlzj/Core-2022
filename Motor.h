#ifndef __MOTOR_H__
#define __MOTOR_H__
#include <AccelStepper.h>

class Motor : public AccelStepper
{
private:
  uint32_t Pin_STP;
  uint32_t Pin_DIR;
  uint32_t Pin_EN;


public:
  Motor(uint32_t STP, uint32_t DIR, uint32_t EN);
  void Enable();
  void Disable();  
};


#endif