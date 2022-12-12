#ifndef __VIBRATOR_H
#define __VIBRATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void Vibrator_Initialize(TIM_HandleTypeDef *htim_p, uint32_t channel);
void Vibrator_Assert(int ms, int pulse);

void Vibrator_Stop();

#ifdef __cplusplus
}
#endif

#endif
