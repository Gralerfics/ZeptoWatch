#ifndef __BATTERY_H
#define __BATTERY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/*
 * BAT_CHRG_R -> PC1
 */

#define __HAL_RCC_BAT_CHRG_R_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define BAT_CHRG_R_GPIO_Port GPIOC
#define BAT_CHRG_R_Pin GPIO_PIN_1

void Battery_Init();

int Battery_IsCharging();
uint16_t Battery_GetADCData();
uint16_t Battery_GetVoltageTimes1000();
uint16_t Battery_GetPowerPercentage();

#ifdef __cplusplus
}
#endif

#endif
