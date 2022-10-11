#include <stdint.h>
#include "pch.h"
#include "Auto.h"
#include <wiring_time.h>

bool Load[5] = {true, true, true, true, false};
Color EPosition = UNRECON;
//================================================
//
//  ######    ###     ####  ##  ##          #
//    ##     ## ##   ##     ## ##         ###
//    ##    ##   ##   ###   ####           ##
//    ##    #######     ##  ## ##          ##
//    ##    ##   ##  ####   ##  ##        ####
//
//================================================

void Start()
{
  // ArmLow();
  while (LineCounter < 1)
  {
    GoDistance(10, 10);
    CountLine();
  }
  LineCounter = 0;
  Stop();
  delay(100);
  ////Buzzer.Stop();
  FrontLineAligment();

  while (LineCounter < 1)
  {
    Moveline(30, 10);
    CountLine();
  }
  LineCounter = 0;
  // //Buzzer.Stop();
  Stop();

  GoDistance(400, 400);
  TurnLeft90();
  // Rotate(-400);
  // GoDistance(200, 140);

  Stop();
}

void TaskOne_CollectPhase1()
{
  GoDistance(100, 100);
  while (LineCounter_Right < 2)
  {
    Moveline(300, 100);
    CountLine_Right();
    // CountLineBoth();
  }
  LineCounter_Right = 0;
  // Buzzer.Stop();

  GoDistance(400, 400);
  TurnRight135();

  ArmLow();
  // LineCounter = 0;
  ResetLineCounter();
  ClearDistance();
  while (LineCounter < 1)
  {
    Go(300);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();

  ClawClose_L(10);
  ClawOpen(10);
  ClawClose_R(10);
  ClawOpen(10);
  ClawClose(2);

  delay(150);
  Color Block2 = GetColor();
  Load[Block2] = true;
  delay(150);
  DiskPosition(Block2);
  ArmTop(10);
  ClawOpen();
  ArmPush();
  delay(1000);

  // ArmLow();

  uint32_t StartMillis = millis();

  while (LineCounter_Left < 1 && LineCounter_Right < 1)
  {
    Go(-200);
    CountLineBoth();
    if (millis() - StartMillis < 500)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  Stop();

  TurnLeft45();

  Stop();
}

void TaskOne_CollectPhase2()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  Stop();

  TurnRight135();

  ArmLow();
  // LineCounter = 0;
  ResetLineCounter();
  ClearDistance();
  while (LineCounter < 1)
  {
    Go(300);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();

  ClawClose_L(10);
  ClawOpen(10);
  ClawClose_R(10);
  ClawOpen(10);
  ClawClose(2);

  delay(150);
  Color Block1 = GetColor();
  Load[Block1] = true;
  delay(150);
  DiskPosition(Block1);
  ArmTop(10);
  ClawOpen();
  ArmPush();
  delay(1000);

  // ArmLow();

  uint32_t StartMillis = millis();

  while (LineCounter_Left < 1 && LineCounter_Right < 1)
  {
    Go(-200);
    CountLineBoth();
    if (millis() - StartMillis < 1000)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  Stop();

  GoDistance(200, 200);
  Stop();
  TurnLeft45();

  Stop();
}

void TaskOne_CollectPhase3()
{
  ClearDistance();
  ResetLineCounter();
  uint32_t StartMillis = millis();
  while (LineCounter_Right < 3)
  {
    LeftLine(300, 100);
    CountLine_Right();
    if (millis() - StartMillis < 1000)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  while (LineCounter_Right < 1)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  Stop();
  GoDistance(400, 400);

  Stop();

  TurnRight135();
  ArmLow();
  // LineCounter = 0;
  ResetLineCounter();
  ClearDistance();
  while (LineCounter < 1)
  {
    Go(300);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();

  // ClawClose(2);

  ClawClose_L(10);
  ClawOpen(10);
  ClawClose_R(10);
  ClawOpen(10);
  ClawClose(2);
  // ClawClose_R(10);
  delay(150);
  Color Block4 = GetColor();
  Load[Block4] = true;
  delay(150);
  DiskPosition(Block4);
  ArmTop(10);
  ClawOpen();
  ArmPush();
  delay(1000);

  // ArmLow();

  StartMillis = millis();

  while (LineCounter_Left < 1 || LineCounter_Right < 1)
  {
    Go(-200);
    CountLineBoth();
    if (millis() - StartMillis < 500)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  Stop();

  TurnLeft45();

  Stop();
}

void TaskOne_CollectPhase4()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  Stop();

  TurnRight135();
  ArmLow();

  // LineCounter = 0;
  ResetLineCounter();
  ClearDistance();
  while (LineCounter < 1)
  {
    Go(300);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();

  ClawClose_L(10);
  ClawOpen(10);
  ClawClose_R(10);
  ClawOpen(10);
  ClawClose(2);

  delay(150);
  Color Block3 = GetColor();
  Load[Block3] = true;
  delay(150);
  DiskPosition(Block3);
  ArmTop(10);
  ClawOpen();
  ArmPush();
  delay(1000);

  // ArmLow();

  uint32_t StartMillis = millis();

  while (LineCounter_Left < 1 && LineCounter_Right < 1)
  {
    Go(-200);
    CountLineBoth();
    if (millis() - StartMillis < 1000)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  Stop();

  TurnLeft45();

  Stop();
}

void BackToCenter()
{
  ResetLineCounter();
  while (LineCounter_Right < 2)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  Stop();

  TurnRight90();

  ResetLineCounter();
  while (LineCounter < 4)
  {
    Moveline(300, 100);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 4 || LineCounter_Right >= 4)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();
  GoDistance(150, 150);

  Stop();
}

// White
void TaskOne_PlacePhase1()
{
  // if loaded go else to blue
  if (Load[WHITE])
  {
    DiskPosition(WHITE);
    ClawOpen();
    ArmTop(10);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);

    ResetLineCounter();
    ClearDistance();
    uint32_t StartMillis = millis();
    while (LineCounter < 1)
    {
      Moveline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    Stop();
    GoDistance(-130, -130);
    Stop();

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);
    ArmTop();

    // TurnRight180();

    StartMillis = millis();
    while (LineCounter < 1)
    {
      Backline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    GoDistance(100, 100);

    Stop();
  }

  TurnLeft90(); // face blue

  Stop();
}

void TaskOne_PlacePhase2()
{
  // if loaded go else to blue
  if (Load[BLUE])
  {
    DiskPosition(BLUE);
    ClawOpen();
    ArmTop(10);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);

    ResetLineCounter();
    ClearDistance();
    uint32_t StartMillis = millis();
    while (LineCounter < 1)
    {
      Moveline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    Stop();
    GoDistance(-130, -130);
    Stop();

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);
    ArmTop();

    // TurnRight180();

    StartMillis = millis();
    while (LineCounter < 1)
    {
      Backline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    GoDistance(100, 100);

    Stop();
  }

  TurnRight180(); // face red

  Stop();
}

void TaskOne_PlacePhase3()
{
  // if loaded go else to blue
  if (Load[RED])
  {
    // TurnLeft90();
    DiskPosition(RED);
    ClawOpen();
    ArmTop(10);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);

    ResetLineCounter();
    ClearDistance();
    uint32_t StartMillis = millis();
    while (LineCounter < 1)
    {
      Moveline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    Stop();
    GoDistance(-130, -130);
    Stop();

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);
    ArmTop();

    // TurnRight180();

    StartMillis = millis();
    while (LineCounter < 1)
    {
      Backline(100, 50);
      CountLine();
      CountLineBoth();
      if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
      {
        break;
      }
      if (millis() - StartMillis < 500)
      {
        ResetLineCounter();
      }
    }
    ResetLineCounter();
    GoDistance(100, 100);

    Stop();
  }

  TurnLeft90(); // face white

  Stop();
}

void TaskOne_PlacePhase4()
{
  // front cross line
  uint32_t StartMillis = millis();
  while (millis() - StartMillis < 500)
  {
    Moveline(100, 50);
  }
  Stop();
  delay(200);

  // back to black position
  ResetLineCounter();
  while (LineCounter < 2)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 2 && LineCounter_Right >= 2)
    {
      break;
    }
  }
  ResetLineCounter();

  // unload black
  if (Load[BLACK])
  {
    ClawOpen();
    DiskPosition(BLACK);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);
    GoDistance(-200, -200);

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);

    ArmTop(10);

    Stop();
  }

  // back to Green
  ResetLineCounter();
  StartMillis = millis();
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
    if (millis() - StartMillis < 800)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();

  if (Load[GREEN])
  {
    ClawOpen();
    DiskPosition(GREEN);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);
    GoDistance(-200, -200);

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);

    ArmTop(10);

    Stop();
  }

  Stop();
}

void BackToHome()
{
  ResetLineCounter();
  ClearDistance();
  while (LineCounter < 2)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 2 && LineCounter_Right >= 2)
    {
      break;
    }
  }
  ResetLineCounter();

  GoDistance(-200, -200);

  Stop();
}

//==================================================
//
//  ######    ###     ####  ##  ##         ####
//    ##     ## ##   ##     ## ##         #    #
//    ##    ##   ##   ###   ####             ##
//    ##    #######     ##  ## ##          ##
//    ##    ##   ##  ####   ##  ##        ######
//
//==================================================
const uint8_t PLANS[16][5] = {{1, 2, 3, 4, 5},
                              {2, 1, 3, 4, 5},
                              {2, 1, 4, 3, 5},
                              {5, 2, 1, 3, 4},
                              {2, 3, 5, 1, 4},
                              {1, 3, 5, 2, 4},
                              {5, 4, 1, 2, 3},
                              {4, 2, 5, 1, 3},
                              {2, 4, 1, 5, 3},
                              {1, 3, 5, 4, 2},
                              {3, 5, 4, 1, 2},
                              {4, 3, 1, 5, 2},
                              {2, 3, 5, 4, 1},
                              {3, 4, 2, 5, 1},
                              {5, 2, 4, 3, 1},
                              {4, 5, 3, 2, 1}};

int8_t Plan = -1;

void TasKTwo_Start()
{
  for (int i = 0; i < 5; i++)
  {
    if (Load[i] == false)
    {
      EPosition = Color(i);
    }
  }

  while (Plan == -1)
  {
    Plan = GetQR();
  }

  Start();
}

void TaskTwo_MovePhase1()
{
  GoDistance(100, 100);
  while (LineCounter_Right < 2)
  {
    Moveline(300, 100);
    CountLine_Right();
    // CountLineBoth();
  }
  LineCounter_Right = 0;
  // Buzzer.Stop();

  GoDistance(400, 400);
  TurnRight90();

  Stop();
}

void TaskTwo_MovePhase2()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(300, 300);
  TurnRight90();

  Stop();
}

void TaskTwo_MovePhase3()
{
  ClearDistance();
  ResetLineCounter();
  uint32_t StartMillis = millis();
  while (LineCounter_Right < 2)
  {
    LeftLine(300, 100);
    CountLine_Right();
    if (millis() - StartMillis < 1000)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  Stop();
  GoDistance(900, 900);

  GoDistance(-800, -200);
  GoDistance(-260, 80);

  ResetLineCounter();
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  Stop();
  GoDistance(-50, -50);

  FrontLineAligment();

  Stop();
}

void TaskTwo_Collect()
{
  // collect 2
  ArmLow();
  GoDistance(200, 200);
  ClawClose_L(2);
  DiskPosition(1);
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  ClawOpen(2);
  ClawClose(2);
  ArmTop(10);
  ClawOpen(2);
  ArmPush();

  // collect 3
  ArmLow();
  GoDistance(200, 200);
  ClawClose_R(2);
  DiskPosition(2);
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  ClawOpen(2);
  ClawClose(2);
  ArmTop(10);
  ClawOpen(2);
  ArmPush();

  // collect 1
  ArmLow();
  GoDistance(400, 400);
  ClawClose_L(2);
  DiskPosition(0);
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  ClawOpen(2);
  ClawClose(2);
  ArmTop(10);
  ClawOpen(2);
  ArmPush();

  // collect 4
  ArmLow();
  GoDistance(400, 400);
  ClawClose_R(2);
  DiskPosition(3);
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  ClawOpen(2);
  ClawClose(2);
  ArmTop(10);
  ClawOpen(2);
  ArmPush();

  // collect 5
  ArmLow();
  GoDistance(600, 600);
  ClawClose_L(10);
  ClawOpen(10);
  ClawClose_R(10);
  ClawOpen(10);
  ClawClose(2);
  DiskPosition(4);
  while (LineCounter < 1)
  {
    Backline(100, 50);
    CountLine();
    CountLineBoth();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
  }
  ResetLineCounter();
  ArmTop(10);
  ClawOpen(2);
  ArmPush();

  GoDistance(400, 400);

  if (EPosition == WHITE)
  {
    // TODO place White then back to line
    TurnRight180();
    
    ResetLineCounter();
    while (LineCounter < 1)
    {
      Moveline(300, 100);
      CountLine();
    }
    ResetLineCounter();
    Stop();

    GoDistance(-200, -200);

    DiskPosition(PLANS[Plan][4] - 1);
    delay(1000);
    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);
    ArmTop();
    TurnLeft180();

    GoDistance(-300, -300);

    ResetLineCounter();
    while (LineCounter < 1)
    {
      Moveline(100, 50);
      CountLine();
      CountLineBoth();
      if(LineCounter_Left > 1 || LineCounter_Right > 1)
      {
        break;
      }
    }
    Stop();
    ResetLineCounter();
    GoDistance(400, 400);
  }

  if (EPosition != BLUE)
  {
    TurnLeft90();
  }
  else
  {
    TurnRight90();
  }

  uint32_t StartMillis = millis();
  while (LineCounter_Left < 1)
  {
    Backline(100, 50);
    CountLine_Left();
    if (LineCounter_Left >= 1 && LineCounter_Right >= 1)
    {
      break;
    }
    if (millis() - StartMillis < 300)
    {
      ResetLineCounter();
    }
  }
  ResetLineCounter();
  FrontLineAligment();

  Stop();
}

//===================================================================================
//
//              ##      #####  #####  ######          #    ####    ####     #  ##
//              ##      ##     ##       ##          ###   #    #  #   ##   #   ##
//              ##      #####  #####    ##           ##      ##     ###   #######
//              ##      ##     ##       ##           ##    ##     #   ##       ##
//              ######  #####  ##       ##          ####  ######   ####        ##
//
//===================================================================================

void TaskTwo_PlacePhase1_LeftOpen()
{
  ResetLineCounter();
  while (LineCounter_Left < 2)
  {
    LeftLine(100, 50);
    CountLine_Left();
    // CountLineBoth();
  }
  LineCounter_Left = 0;
  // Buzzer.Stop();

  GoDistance(-180, -180);
  Stop();

  DiskPosition(PLANS[Plan][0] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void TaskTwo_PlacePhase2_LeftOpen()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(100, 50);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  TurnLeft90();

  while (LineCounter_Left < 1)
  {
    Backline(100, 50);
    CountLine_Left();
    // CountLineBoth();
  }
  LineCounter_Left = 0;
  // Buzzer.Stop();
  GoDistance(-200, -200);
  Stop();

  DiskPosition(PLANS[Plan][1] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void TaskTwo_PlacePhase3_LeftOpen()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  TurnLeft90();

  while (LineCounter_Left < 1)
  {
    Backline(100, 50);
    CountLine_Left();
    // CountLineBoth();
  }
  LineCounter_Left = 0;
  // Buzzer.Stop();
  GoDistance(-200, -200);
  Stop();

  DiskPosition(PLANS[Plan][2] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void TaskTwo_PlacePhase4_LeftOpen()
{
  ResetLineCounter();
  while (LineCounter_Right < 4)
  {
    Moveline(300, 100);
    CountLine_Right();
  }
  ResetLineCounter();
  Stop();

  GoDistance(-180, -180);
  Stop();

  DiskPosition(PLANS[Plan][3] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void FinalHome_LeftOpen()
{
  while (LineCounter_Left < 2)
  {
    Moveline(300, 100);
    CountLine_Left();
    // CountLineBoth();
  }
  LineCounter_Left = 0;
  // Buzzer.Stop();
  GoDistance(400, 400);

  TurnLeft90();

  BackToHome();
  Stop();
}
//============================================================================================
//
//              #####    ##   ####    ##   ##  ######         ####     #     #  ##   ####
//              ##  ##   ##  ##       ##   ##    ##          #    #  ###    #   ##  #   ##
//              #####    ##  ##  ###  #######    ##             ##    ##   #######    ###
//              ##  ##   ##  ##   ##  ##   ##    ##           ##      ##        ##  #   ##
//              ##   ##  ##   ####    ##   ##    ##          ######  ####       ##   ####
//
//============================================================================================

void TaskTwo_PlacePhase1_RightOpen()
{
  ResetLineCounter();
  while (LineCounter_Right < 2)
  {
    Moveline(100, 50);
    CountLine_Right();
    // CountLineBoth();
  }
  LineCounter_Right = 0;
  // Buzzer.Stop();

  GoDistance(-180, -180);
  Stop();

  DiskPosition(PLANS[Plan][1] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void TaskTwo_PlacePhase2_RightOpen()
{
  ResetLineCounter();
  while (LineCounter_Left < 4)
  {
    Moveline(100, 50);
    CountLine_Left();
  }
  ResetLineCounter();
  Stop();
  GoDistance(400, 400);

  TurnRight90();

  while (LineCounter_Right < 1)
  {
    Backline(100, 50);
    CountLine_Right();
    // CountLineBoth();
  }
  LineCounter_Right = 0;
  // Buzzer.Stop();
  GoDistance(-200, -200);
  Stop();

  DiskPosition(PLANS[Plan][0] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}
void TaskTwo_PlacePhase3_RightOpen()
{
  ResetLineCounter();
  while (LineCounter_Left < 2)
  {
    Moveline(300, 100);
    CountLine_Left();
  }
  Stop();
  ResetLineCounter();
  if (EPosition == BLUE)
  {
    Stop();
    GoDistance(400, 400);

    TurnLeft90();

    ResetLineCounter();
    while (LineCounter < 1)
    {
      Moveline(300, 100);
      CountLine();
    }
    ResetLineCounter();
    Stop();

    GoDistance(-200, -200);

    DiskPosition(PLANS[Plan][4] - 1);
    delay(1000);
    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);
    ClawClose(2);

    ArmLow(10);
    ClawOpen(2);

    ClawClose_R(2);
    ClawOpen(2);
    ClawClose_L(2);
    ClawOpen(2);

    GoDistance(-200, -200);
    ArmTop();
    TurnLeft180();

    GoDistance(-300, -300);

    ResetLineCounter();
    while (LineCounter < 1)
    {
      Moveline(100, 50);
      CountLine();
      CountLineBoth();
      if(LineCounter_Left > 1 || LineCounter_Right > 1)
      {
        break;
      }
    }
    Stop();
    ResetLineCounter();
    GoDistance(400, 400);
    TurnLeft90();
  }

  ResetLineCounter();
  while (LineCounter_Left < 2)
  {
    Moveline(300, 100);
    CountLine_Left();
  }
  ResetLineCounter();
  Stop();

  GoDistance(400, 400);
  TurnRight90();

  while (LineCounter_Right < 1)
  {
    Backline(100, 50);
    CountLine_Right();
    // CountLineBoth();
  }
  ResetLineCounter();
  // Buzzer.Stop();
  GoDistance(-200, -200);
  Stop();

  DiskPosition(PLANS[Plan][3] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();
//*/
  Stop();
}
void TaskTwo_PlacePhase4_RightOpen()
{
  ResetLineCounter();
  while (LineCounter_Left < 4)
  {
    Moveline(300, 100);
    CountLine_Left();
  }
  ResetLineCounter();
  Stop();

  GoDistance(-180, -180);
  Stop();

  DiskPosition(PLANS[Plan][2] - 1);
  delay(1000);
  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);
  ClawClose(2);

  ArmLow(10);
  ClawOpen(2);

  ClawClose_R(2);
  ClawOpen(2);
  ClawClose_L(2);
  ClawOpen(2);

  GoDistance(-200, -200);
  ArmTop();
  TurnLeft180();

  Stop();
}

void FinalHome_RightOpen()
{
  while (LineCounter_Right < 2)
  {
    Moveline(300, 100);
    CountLine_Right();
    // CountLineBoth();
  }
  LineCounter_Right = 0;
  // Buzzer.Stop();
  GoDistance(400, 400);

  TurnRight90();

  BackToHome();
  Stop();
}