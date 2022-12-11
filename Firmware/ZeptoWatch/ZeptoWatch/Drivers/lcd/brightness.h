#ifndef __BRIGHTNESS_H
#define __BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void Brightness_Start(TIM_HandleTypeDef *htim, uint32_t channel);

void Brightness_SetValue(uint8_t val);
uint8_t Brightness_GetValue();
uint8_t Brightness_GetValueDirect();

void Brightness_GoDark();
void Brightness_LightUp();

#ifdef __cplusplus
}
#endif

#endif
