#include "pch.h"
#include "RobotConfig.h"

LED BlueLED(PD_2);
LED GreenLED(PA_8);

// TwoWire Wire(PB_7, PB_6);
TwoWire Wire2(PB_11, PB_10);

HardwareSerial Serial1(PA_10, PA_9);
HardwareSerial Serial4(PC_11, PC_10);

ServoWithStep Svo_Disk(PC6);
ServoWithStep Svo_Arm(PC7);
ServoWithStep Svo_Left(PC8);
ServoWithStep Svo_Right(PC9);

// STP DIR EN
Motor MotorL(PB12, PB14, PA15);
Motor MotorR(PB13, PB15, PC12);


Linetracker LT_LWNG(PA_1);
Linetracker LT_LOUT(PA_2);
Linetracker LT_LMID(PA_3);
Linetracker LT_LINR(PA_4);
Linetracker LT_AXIS(PA_5);
Linetracker LT_RINR(PB_0);
Linetracker LT_RMID(PB_1);
Linetracker LT_ROUT(PC_4);
Linetracker LT_RWNG(PC_5);

Linetracker LT_BLFT(PC_3);
Linetracker LT_BMID(PC_2);
Linetracker LT_BRGT(PC_1);



Scanner QRScanner(&Serial4, PB_8);

Beeper Buzzer(PB9);

Adafruit_TCS34725 ColorSensor(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);