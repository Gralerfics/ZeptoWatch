#ifndef __BRIGHTNESS_H
#define __BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/* ==================== Body ==================== */
extern uint8_t LCD_BRIGHTNESS_Value;

void LCD_BRIGHTNESS_SetValue(uint8_t val);
void LCD_BRIGHTNESS_SetTIMHandle(TIM_HandleTypeDef *htim);
void LCD_BRIGHTNESS_SetTIMChannel(uint32_t channel);

void LCD_BRIGHTNESS_ApplyValue();

#ifdef __cplusplus
}
#endif

#endif
