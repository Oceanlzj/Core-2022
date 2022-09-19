#ifndef __BASICFUNCTIONS_H__
#define __BASICFUNCTIONS_H__

enum Color
{
  BLACK = 0,
  WHITE = 1,
  RED = 2,
  GREEN = 3,
  BLUE = 4,
  UNRECON = 5
};

// extern bool Aligned;
extern uint16_t LineCounter;
extern bool LineCounterFlag;
extern uint16_t LineCounter_Left;
extern bool LineCounterFlag_Left;
extern uint16_t LineCounter_Right;
extern bool LineCounterFlag_Right;

void ColorSensorInit();
void ServoInit();
void MotorInit();
void SetGoDistance(int32_t L_Distance, uint32_t R_distance);
void ClearDistance();
void Chassis(int32_t Spd_L, int32_t Spd_R);
uint8_t GetFrontLine();
void Goline(uint32_t Spd, uint32_t Spd_dif);
void LeftLine(uint32_t Spd, uint32_t Spd_dif);
void GoDistance(int64_t Distance_L, int64_t Distance_R);
void SetDistance(int64_t Distance_L, int64_t Distance_R);
void Moveline(int64_t Spd, int64_t Spd_dif);
void FrontLineAligment();
void Go(int32_t Dis);
void Backline(int64_t Spd, int64_t Spd_dif);
void Moveline_Back(int64_t Spd, int64_t Spd_dif);
void Moveline_Edge(int64_t Spd, int64_t Spd_dif);
void ResetLineCounter();
void Stop();
void CountLine();
void CountLine_Left();
void CountLine_Right();
void CountLineBoth();
void Rotate(int32_t Distance);
void ClawClose();
void ClawClose(uint16_t Spd);
void ClawClose_L(uint16_t spd);
void ClawClose_R(uint16_t spd);
void ClawOpen();
void ClawOpen(uint16_t Spd);
void ArmTop();
void ArmTop(uint8_t spd);
void ArmLow();
void ArmLow(uint8_t spd);
void ArmPush();
void DiskPosition(Color Color);
void DiskPosition(uint8_t pos);
void PrintALlLineTracker();
void TurnLeft45();
void TurnLeft90();
void TurnLeft135();
void TurnLeft180();
void TurnRight45();
void TurnRight90();
void TurnRight135();
void TurnRight180();
Color GetColor();
int8_t GetQR();

#endif