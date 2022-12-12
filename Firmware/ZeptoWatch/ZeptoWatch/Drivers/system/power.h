#ifndef __POWER_H
#define __POWER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void Power_SetTIMHandle(TIM_HandleTypeDef *htim);

int Power_GetState();
void Power_SetState(int state);

void Power_InterruptHandler_Key();
void Power_InterruptHandler_Tim();

#ifdef __cplusplus
}
#endif

#endif
