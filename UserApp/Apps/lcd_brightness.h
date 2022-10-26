#ifndef ZEPTOWATCH_LCD_BRIGHTNESS_H
#define ZEPTOWATCH_LCD_BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

extern uint8_t LCD_BRIGHTNESS_Value;

void LCD_BRIGHTNESS_SetValue(uint8_t val);

void LCD_BRIGHTNESS_ApplyValue(TIM_HandleTypeDef *htim, uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif
