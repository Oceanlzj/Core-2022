#include "pch.h"
#include "RobotConfig.h"

void setup()
{
  Serial1.begin(9600);
  Serial4.begin(115200);
  ColorSensorInit();
  MotorInit();

  ServoInit();
  QRScanner.Reset();
  delay(500);
  BlueLED.Off();
  // Buzzer.Beep(2000, 2000);

  //=======================================
  //
  //    ###    ##   ##  ######   #####
  //   ## ##   ##   ##    ##    ##   ##
  //  ##   ##  ##   ##    ##    ##   ##
  //  #######  ##   ##    ##    ##   ##
  //  ##   ##   #####     ##     #####
  //
  //=======================================

  Start();

  TaskOne_CollectPhase1();
  TaskOne_CollectPhase2();
  TaskOne_CollectPhase3();
  TaskOne_CollectPhase4();

  BackToCenter();

  TaskOne_PlacePhase1();
  TaskOne_PlacePhase2();
  TaskOne_PlacePhase3();
  TaskOne_PlacePhase4();

  BackToHome();

  TasKTwo_Start();
  TaskTwo_MovePhase1();
  TaskTwo_MovePhase2();
  TaskTwo_MovePhase3();

  TaskTwo_Collect();

  // LeftOpenRoute or RightOpenRoute
  if (EPosition != BLUE)
  {
    TaskTwo_PlacePhase1_LeftOpen();
    TaskTwo_PlacePhase2_LeftOpen();
    TaskTwo_PlacePhase3_LeftOpen();
    TaskTwo_PlacePhase4_LeftOpen();

    FinalHome_LeftOpen();
  }
  else
  {
    TaskTwo_PlacePhase1_RightOpen();
    TaskTwo_PlacePhase2_RightOpen();
    TaskTwo_PlacePhase3_RightOpen();
    TaskTwo_PlacePhase4_RightOpen();

    FinalHome_RightOpen();
  }

  //*/
  // GoDistance(400, 400);

  Stop();
}

void loop()
{
  BlueLED.Toggle();
  GreenLED.Toggle();
  // Buzzer.Beep(440, 50);
  delay(200);
}