#ifndef __BRIGHTNESS_H
#define __BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void Brightness_SetTIMHandle(TIM_HandleTypeDef *htim);
void Brightness_SetTIMChannel(uint32_t channel);
void Brightness_Start();

void Brightness_SetValue(uint8_t val);
uint8_t Brightness_GetValue();

#ifdef __cplusplus
}
#endif

#endif
