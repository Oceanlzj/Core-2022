#include "pch.h"
#include "RobotConfig.h"

void setup()
{
  Serial1.begin(115200);
  Serial4.begin(115200);
  ColorSensorInit();
  MotorInit();

  ServoInit();
  QRScanner.Reset();
  delay(500);
  BlueLED.Off();
  // ClawClose();
  // ArmLow(10);

  //=======================================
  //
  //    ###    ##   ##  ######   #####
  //   ## ##   ##   ##    ##    ##   ##
  //  ##   ##  ##   ##    ##    ##   ##
  //  #######  ##   ##    ##    ##   ##
  //  ##   ##   #####     ##     #####
  //
  //=======================================
  delay(1000);
/*
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

  TaskTwo_PlacePhase1();
  TaskTwo_PlacePhase2();*/
  TaskTwo_PlacePhase3();
  TaskTwo_PlacePhase4();

  FinalHome();
  // GoDistance(200, 200);*/
  // millis()

  Stop();
}

void loop()
{
  /*
  DiskPosition(0);
  ArmLow();

  ClawOpen();
  delay(1000);
  ClawClose();
  delay(1000);

  ArmTop();
  delay(1000);
  ClawOpen();
  delay(1000);
  ClawClose();
  delay(1000);
  // Backline(100, 50);
  /*
    for (int i = 0; i < 5; i++)
    {
      DiskPosition(i);
      delay(2000);
      ClawClose_R(2);
      ClawOpen(2);
      ClawClose_L(2);
      ClawOpen(2);
      ClawClose(2);
      delay(3000);
      ClawOpen(2);
    }

    // Moveline_Back(100, 50);
    /*
      ClawClose(10);
      delay(500);
      ClawOpen(10);
      delay(500);
      // Serial1.println(GetColor());
      // delay(1000);
      //  Buzzer.Beep(440);
      //  delay(300);
      //  Buzzer.Stop();
      //  QRScanner.Scan();
      //  delay(5000);
      //  QRScanner.Reset();
      //  SetDistance(3000, 500);
      //  otorL.run();
      //  MotorR.run();
      //   LeftLine(200, 100);
      //   GoDistance(100, 100);
      //  Goline(500, 300);
      //  Moveline(300, 100);
      //  PrintALlLineTracker();
      //  Serial1.println(GetFrontLine());*/
  BlueLED.Toggle();
  GreenLED.Toggle();
  delay(200);
}