#ifndef __AUTO_H__
#define __AUTO_H__
#include "BasicFunctions.h"

extern Color EPosition;
extern int8_t Plan;

void Start();

void TaskOne_CollectPhase1();
void TaskOne_CollectPhase2();
void TaskOne_CollectPhase3();
void TaskOne_CollectPhase4();
void BackToCenter();
void TaskOne_PlacePhase1();
void TaskOne_PlacePhase2();
void TaskOne_PlacePhase3();
void TaskOne_PlacePhase4();
void BackToHome();

void TasKTwo_Start();
void TaskTwo_MovePhase1();
void TaskTwo_MovePhase2();
void TaskTwo_MovePhase3();
void TaskTwo_Collect();

void TaskTwo_PlacePhase1_LeftOpen();
void TaskTwo_PlacePhase2_LeftOpen();
void TaskTwo_PlacePhase3_LeftOpen();
void TaskTwo_PlacePhase4_LeftOpen();
void FinalHome_LeftOpen();

void TaskTwo_PlacePhase1_RightOpen();
void TaskTwo_PlacePhase2_RightOpen();
void TaskTwo_PlacePhase3_RightOpen();
void TaskTwo_PlacePhase4_RightOpen();
void FinalHome_RightOpen();

#endif