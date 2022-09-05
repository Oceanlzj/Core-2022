#ifndef __ROBOTCONFIG_H__
#define __ROBOTCONFIG_H__

#include <LED.h>
#include <Wire.h>
#include <HardwareSerial.h>

#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>

#include "Motor.h"
#include "Linetracker.h"
#include "ServoWithStep.h"

#define SPEEDFIXINDEX 1
#define DISTANCEFIXINDEX 1

#define R_Close 1400
#define R_Open 2200
#define L_Close 1700
#define L_Open 800
#define ARM_TOP 500
#define ARM_LOW 2500

#define LT_THRESHOLD 200

extern LED BlueLED;
extern LED GreenLED;

extern TwoWire Wire2;

extern HardwareSerial Serial1;
extern HardwareSerial Serial4;

extern ServoWithStep Svo_Disk;
extern ServoWithStep Svo_Arm;
extern ServoWithStep Svo_Left;
extern ServoWithStep Svo_Right;

extern Motor MotorL;
extern Motor MotorR;

extern Linetracker LT_LWNG;
extern Linetracker LT_LOUT;
extern Linetracker LT_LMID;
extern Linetracker LT_LINR;
extern Linetracker LT_AXIS;
extern Linetracker LT_RINR;
extern Linetracker LT_RMID;
extern Linetracker LT_ROUT;
extern Linetracker LT_RWNG;
extern Linetracker LT_BLFT;
extern Linetracker LT_BMID;
extern Linetracker LT_BRGT;


extern Beeper Buzzer;
extern Scanner QRScanner;
extern Adafruit_TCS34725 ColorSensor;
// extern Adafruit_HMC5883_Unified MagSensor;
// extern Adafruit_NeoPixel RGBLights;

#endif