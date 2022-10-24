#include "pch.h"

void ColorSensorInit()
{
  Wire2.begin();
  delay(100);
  // ColorSensor.begin();
  if (ColorSensor.begin(TCS34725_ADDRESS, &Wire2))
  {
    return;
  }
  else
  {
    Serial1.println("Color Sensor Error");
  }
}

void ServoInit()
{
  Svo_Arm.Init(ARM_TOP);
  Svo_Disk.Init(500);
  Svo_Left.Init(L_Close);
  Svo_Right.Init(R_Close);

  Svo_Arm.writeMicroseconds(ARM_TOP);
  Svo_Disk.writeMicroseconds(500);
  Svo_Left.writeMicroseconds(L_Open);
  Svo_Right.writeMicroseconds(R_Open);
}

void MotorInit()
{
  MotorL.setMaxSpeed(1500 * SPEEDFIXINDEX);
  MotorL.setAcceleration(1000 * SPEEDFIXINDEX);
  MotorL.Enable();

  MotorR.setMaxSpeed(1500 * SPEEDFIXINDEX);
  MotorR.setAcceleration(1000 * SPEEDFIXINDEX);
  MotorR.Enable();

  ClearDistance();
}

void SetGoDistance(int32_t L_Distance, uint32_t R_distance)
{
  MotorL.move(L_Distance * DISTANCEFIXINDEX);
  MotorR.move(R_distance * DISTANCEFIXINDEX);
}

void ClearDistance()
{
  MotorL.setCurrentPosition(0);
  MotorR.setCurrentPosition(0);
  MotorL.moveTo(0);
  MotorR.moveTo(0);
}

void Go(int32_t Dis)
{
  MotorL.move(Dis);
  MotorR.move(-Dis);

  MotorL.run();
  MotorR.run();
}

bool LeftWing = false;
bool LeftDeBoucing = false;
uint16_t LeftMills = 0;
void RefreshWing_L()
{
  if (LeftDeBoucing)
  {
    if (millis() - LeftMills > 20)
    {
      if (LT_LWNG.OnLine())
      {
        LeftWing = true;
      }
      else
      {
        LeftWing = false;
      }
    }
  }
  else
  {
    if (LT_LWNG.OnLine())
    {
      LeftDeBoucing = true;
      LeftMills = millis();
    }
    else
    {
      LeftWing = false;
    }
  }
}

bool RightWing = false;
bool RightDeBoucing = false;
uint16_t RightMills = 0;
void RefreshWing_R()
{
  if (RightDeBoucing)
  {
    if (millis() - RightMills > 20)
    {
      if (LT_RWNG.OnLine())
      {
        RightWing = true;
      }
      else
      {
        RightWing = false;
      }
    }
  }
  else
  {
    if (LT_RWNG.OnLine())
    {
      RightDeBoucing = true;
      RightMills = millis();
    }
    else
    {
      RightWing = false;
    }
  }
}

uint8_t GetFrontLine()
{
  uint8_t Result = 0;

  Result += LT_LOUT.OnLine() ? 64 : 0;
  Result += LT_LMID.OnLine() ? 32 : 0;
  Result += LT_LINR.OnLine() ? 16 : 0;
  Result += LT_AXIS.OnLine() ? 8 : 0;
  Result += LT_RINR.OnLine() ? 4 : 0;
  Result += LT_RMID.OnLine() ? 2 : 0;
  Result += LT_RMID.OnLine() ? 1 : 0;

  return Result;
}

void LeftLine(uint32_t Spd, uint32_t Spd_dif)
{
  // Chassis(Spd, Spd);
  if (LT_LMID.OnLine())
  {
    if (LT_LOUT.OnLine() && !LT_LINR.OnLine())
    {
      SetDistance(Spd, Spd + Spd_dif * 2);
    }
    else if (!LT_LOUT.OnLine() && LT_LINR.OnLine())
    {
      SetDistance(Spd + Spd_dif * 2, Spd);
    }
    else
    {
      SetDistance(Spd, Spd);
    }
  }
  else
  {
    if (LT_LOUT.OnLine() && !LT_LINR.OnLine())
    {
      SetDistance(Spd - Spd_dif, Spd + Spd_dif * 2);
    }
    else if (!LT_LOUT.OnLine() && LT_LINR.OnLine())
    {
      SetDistance(Spd + Spd_dif * 2, Spd - Spd_dif);
    }
    else
    {
      SetDistance(Spd, Spd);
    }
  }
  MotorL.run();
  MotorR.run();
}

void GoDistance(int64_t Distance_L, int64_t Distance_R)
{
  ClearDistance();
  MotorL.move(Distance_L * DISTANCEFIXINDEX);
  MotorR.move(-Distance_R * DISTANCEFIXINDEX);

  while (MotorL.distanceToGo() != 0 || MotorR.distanceToGo() != 0)
  {
    MotorL.run();
    MotorR.run();
  }
}

void SetDistance(int64_t Distance_L, int64_t Distance_R)
{
  MotorL.move(Distance_L * DISTANCEFIXINDEX);
  MotorR.move(-Distance_R * DISTANCEFIXINDEX);
}

void SetDistance_Back(int64_t Distance_L, int64_t Distance_R)
{
  MotorL.move(-Distance_L * DISTANCEFIXINDEX);
  MotorR.move(Distance_R * DISTANCEFIXINDEX);
}

void Moveline(int64_t Spd, int64_t Spd_dif)
{
  switch (GetFrontLine())
  {
  case 1:
    SetDistance(Spd * 3, 0);
    break;
  case 3:
    SetDistance(Spd * 2, 0);
    break;
  case 2:
    SetDistance(Spd + Spd_dif, 0);
    break;
  case 6:
    SetDistance(Spd, 50);
    break;

  case 4:
    SetDistance(Spd + 2.2 * Spd_dif, Spd - Spd_dif);
    break;
  case 12:
    SetDistance(Spd + 2.2 * Spd_dif, Spd);
    break;

  case 8:
    SetDistance(Spd, Spd);
    break;

  case 24:
    SetDistance(Spd, Spd + 2.2 * Spd_dif);
    break;
  case 16:
    SetDistance(Spd - Spd_dif, Spd + 2.2 * Spd_dif);
    break;

  case 48:
    SetDistance(50, Spd);
    break;
  case 32:
    SetDistance(0, Spd + Spd_dif);
    break;
  case 96:
    SetDistance(0, Spd * 2);
    break;
  case 64:
    SetDistance(0, Spd * 3);
    break;

  case 0:
    GreenLED.Toggle();
    if (LT_BMID.OnLine())
    {
      if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
      {
        SetDistance(Spd, Spd + Spd_dif * 2);
      }
      else if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
      {
        SetDistance(Spd + Spd_dif * 2, Spd);
      }
      else
      {
        SetDistance(Spd, Spd);
      }
    }
    else
    {
      if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
      {
        SetDistance(Spd - Spd_dif, Spd + Spd_dif * 2);
      }
      else if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
      {
        SetDistance(Spd + Spd_dif * 2, Spd - Spd_dif);
      }
      else
      {
        SetDistance(Spd, Spd);
      }
    }
    break;

  default:
    SetDistance(Spd, Spd);
    break;
  }
  MotorL.run();
  MotorR.run();
}

void Backline(int64_t Spd, int64_t Spd_dif)
{
  if (LT_BMID.OnLine())
  {
    if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
    {
      SetDistance_Back(Spd, Spd + Spd_dif * 2);
    }
    else if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
    {
      SetDistance_Back(Spd + Spd_dif * 2, Spd);
    }
    else
    {
      SetDistance_Back(Spd, Spd);
    }
  }
  else
  {
    if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
    {
      SetDistance_Back(Spd - Spd_dif, Spd + Spd_dif * 2);
    }
    else if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
    {
      SetDistance_Back(Spd + Spd_dif * 2, Spd - Spd_dif);
    }
    else
    {
      SetDistance_Back(Spd, Spd);
    }
  }
  MotorL.run();
  MotorR.run();
}
// used for edge
void Moveline_Edge(int64_t Spd, int64_t Spd_dif)
{
  switch (GetFrontLine())
  {
  case 1:
    SetDistance(Spd * 3, 0);
    break;
  case 3:
    SetDistance(Spd * 2, 0);
    break;
  case 2:
    SetDistance(Spd + Spd_dif, 0);
    break;
  case 6:
    SetDistance(Spd, 50);
    break;

  case 4:
    SetDistance(Spd + 2.2 * Spd_dif, Spd - Spd_dif);
    break;
  case 12:
    SetDistance(Spd + 2.2 * Spd_dif, Spd);
    break;

  case 8:
    SetDistance(Spd, Spd);
    break;

  case 24:
    SetDistance(Spd, Spd + 2.2 * Spd_dif);
    break;
  case 16:
    SetDistance(Spd - Spd_dif, Spd + 2.2 * Spd_dif);
    break;

  case 0:
    if (LT_BMID.OnLine())
    {
      if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
      {
        SetDistance(Spd, Spd + Spd_dif * 2);
      }
      else if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
      {
        SetDistance(Spd + Spd_dif * 2, Spd);
      }
      else
      {
        SetDistance(Spd, Spd);
      }
    }
    else
    {
      if (!LT_BLFT.OnLine() && LT_BRGT.OnLine())
      {
        SetDistance(Spd - Spd_dif, Spd + Spd_dif * 2);
      }
      else if (LT_BLFT.OnLine() && !LT_BRGT.OnLine())
      {
        SetDistance(Spd + Spd_dif * 2, Spd - Spd_dif);
      }
      else
      {
        SetDistance(Spd, Spd);
      }
    }
    break;

  default:
    SetDistance(Spd, Spd);
    break;
  }
  MotorL.run();
  MotorR.run();
}

void FrontLineAligment()
{
  while (!LT_LOUT.OnLine() || !LT_RMID.OnLine())
  {
    if (LT_LOUT.OnLine() && LT_RMID.OnLine())
    {
      break;
    }
    else if (!LT_LOUT.OnLine() && LT_RMID.OnLine())
    {
      GoDistance(1, 0);
    }
    else if (LT_LOUT.OnLine() && !LT_RMID.OnLine())
    {
      GoDistance(0, 1);
    }
    else
    {
      GoDistance(1, 1);
    }
  }
}

//~235 45
void Rotate(int32_t Distance)
{
  ClearDistance();
  MotorL.move(Distance);
  MotorR.move(Distance);

  while (MotorL.distanceToGo() != 0 || MotorR.distanceToGo() != 0)
  {
    MotorL.run();
    MotorR.run();
  }
}

void TurnLeft45()
{
  Rotate(-240);
}
void TurnLeft90()
{
  Rotate(-480);
}
void TurnLeft135()
{
  Rotate(-705);
}
void TurnLeft180()
{
  Rotate(-960);
}
void TurnRight45()
{
  Rotate(234);
}
void TurnRight90()
{
  Rotate(480);
}
void TurnRight135()
{
  Rotate(705);
}
void TurnRight180()
{
  Rotate(960);
}

void Stop()
{
  MotorR.stop();
  MotorL.stop();
  ClearDistance();
}

uint16_t LineCounter = 0;
bool LineCounterFlag = false;
// linecount
void CountLine()
{
  RefreshWing_L();
  RefreshWing_R();
  if (LeftWing && LT_RWNG.OnLine() && !LineCounterFlag)
  {
    LineCounterFlag = true;
    LineCounter++;
    Buzzer.Beep(1440);
  }
  else if (!LeftWing && !RightWing && LineCounterFlag)
  {
    LineCounterFlag = false;
  }
}

uint16_t LineCounter_Left = 0;
bool LineCounterFlag_Left = false;
void CountLine_Left()
{
  RefreshWing_L();
  if (LeftWing && !LineCounterFlag_Left)
  {
    LineCounterFlag_Left = true;
    LineCounter_Left++;
    Buzzer.Beep(440);
  }
  else if (!LeftWing && LineCounterFlag_Left)
  {
    LineCounterFlag_Left = false;
    // ClearDistance();
  }
}

uint16_t LineCounter_Right = 0;
bool LineCounterFlag_Right = false;
bool LineCounterDeboucing_Right = false;
void CountLine_Right()
{
  RefreshWing_R();
  if (RightWing && !LineCounterFlag_Right)
  {
    LineCounterFlag_Right = true;
    LineCounter_Right++;
    Buzzer.Beep(880);
  }
  else if (!RightWing && LineCounterFlag_Right)
  {
    LineCounterFlag_Right = false;
    // ClearDistance();
  }
}

void CountLineBoth()
{
  CountLine_Left();
  CountLine_Right();
}

void ResetLineCounter()
{
  LineCounter = 0;
  LineCounter_Left = 0;
  LineCounter_Right = 0;
}

void ClawClose()
{
  Svo_Left.writeMicroseconds(L_Close);
  Svo_Right.writeMicroseconds(R_Close);
}

void ClawClose(uint16_t Spd)
{
  int16_t Spd_L = Svo_Left.readMicroseconds() > L_Close ? -Spd : Spd;
  int16_t Spd_R = Svo_Right.readMicroseconds() > R_Close ? -Spd : Spd;

  while (abs(Svo_Left.readMicroseconds() - L_Close) > Spd && abs(Svo_Right.readMicroseconds() - R_Close) > Spd)
  {
    Svo_Left.writeMicroseconds(Svo_Left.readMicroseconds() + Spd_L);
    Svo_Right.writeMicroseconds(Svo_Right.readMicroseconds() + Spd_R);
    delay(Spd / 2);
  }
  Svo_Left.writeMicroseconds(L_Close);
  Svo_Right.writeMicroseconds(R_Close);
}

void ClawClose_L(uint16_t spd)
{
  Svo_Left.Setpos(L_Close, spd);
}

void ClawClose_R(uint16_t spd)
{
  Svo_Right.Setpos(R_Close, spd);
}

void ClawOpen()
{
  Svo_Left = L_Open;
  Svo_Right = R_Open;
}

void ClawOpen(uint16_t Spd)
{
  int16_t Spd_L = Svo_Left.readMicroseconds() > L_Open ? -Spd : Spd;
  int16_t Spd_R = Svo_Right.readMicroseconds() > R_Open ? -Spd : Spd;

  while (abs(Svo_Left.readMicroseconds() - L_Open) > Spd && abs(Svo_Right.readMicroseconds() - R_Open) > Spd)
  {
    Svo_Left.writeMicroseconds(Svo_Left.readMicroseconds() + Spd_L);
    Svo_Right.writeMicroseconds(Svo_Right.readMicroseconds() + Spd_R);
    delay(Spd / 2);
  }
  Svo_Left.writeMicroseconds(L_Open);
  Svo_Right.writeMicroseconds(R_Open);
}

void ArmTop()
{
  Svo_Arm = ARM_TOP;
  delay(1000);
}
void ArmTop(uint8_t spd)
{
  Svo_Arm.Setpos(ARM_TOP, spd);
  delay(500);
}
void ArmLow()
{
  Svo_Arm = ARM_LOW;
  delay(1000);
}

void ArmPush()
{
  Svo_Arm = ARM_PUSH;
  delay(500);
  Svo_Arm = ARM_TOP;
  delay(300);
}

void ArmLow(uint8_t spd)
{
  Svo_Arm.Setpos(ARM_LOW, spd);
  delay(500);
}

const uint16_t DISK_POS[6] = {560, 1020, 1520, 2040, 2480, 0};
void DiskPosition(Color Color)
{
  Svo_Disk = DISK_POS[Color];
  delay(1000);
}

void DiskPosition(uint8_t pos)
{
  Svo_Disk = DISK_POS[pos];
  delay(1000);
}

Color GetColor()
{
  uint16_t R = 0;
  uint16_t G = 0;
  uint16_t B = 0;
  uint16_t C = 0;
  ClawClose(10);
  delay(600);
  ColorSensor.getRawData(&R, &G, &B, &C);
  // TODO:: Process Color
  Serial1.printf("%d, %d, %d, %d\r\n", R, G, B, C);

  if (C > 10000)
  {
    return WHITE;
  }
  else if (R < 1000 && G < 1000 && B < 1000)
  {
    return BLACK;
  }
  else if (R > G && R > B)
  {
    return RED;
  }
  else if (G > R && G > B)
  {
    return GREEN;
  }
  else if (B > R && B > G)
  {
    return BLUE;
  }
  else
  {
    return UNRECON;
  }
}

int8_t GetQR()
{
  String QRInfo = "";
  QRScanner.Reset();
  delay(2);
  QRInfo = QRScanner.Scan();
  // Serial1.println(QRInfo);
  //  TODO: Process QRInfo
  char QRResult[3];
  QRResult[0] = (QRInfo[0] > '0' && QRInfo[0] < '9') ? QRInfo[0] : 0;
  QRResult[1] = (QRInfo[1] >= '0' && QRInfo[1] < '9') ? QRInfo[1] : 0;
  QRResult[2] = 0;

  if (QRResult[0] == 0)
  {
    return -1;
  }

  if (QRResult[1] == 0)
  {
    return QRResult[0] - '1';
  }
  else
  {
    return (QRResult[0] - '0') * 10 + QRResult[1] - '1';
  }
}

void PrintALlLineTracker()
{
  Serial1.print(LT_LWNG.OnLine());
  Serial1.print(',');
  Serial1.print(LT_LOUT.OnLine());
  Serial1.print(',');
  Serial1.print(LT_LMID.OnLine());
  Serial1.print(',');
  Serial1.print(LT_LINR.OnLine());
  Serial1.print(',');
  Serial1.print(LT_AXIS.OnLine());
  Serial1.print(',');
  Serial1.print(LT_RINR.OnLine());
  Serial1.print(',');
  Serial1.print(LT_RMID.OnLine());
  Serial1.print(',');
  Serial1.print(LT_RWNG.OnLine());
  Serial1.print('\n');
}