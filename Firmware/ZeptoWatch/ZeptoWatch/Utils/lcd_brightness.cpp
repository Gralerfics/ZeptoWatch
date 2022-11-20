#include "lcd_brightness.h"

uint8_t LCD_BRIGHTNESS_Value = 60;

void LCD_BRIGHTNESS_SetValue(uint8_t val) {
	if (LCD_BRIGHTNESS_Value >= 0 && LCD_BRIGHTNESS_Value <= 100) {
		LCD_BRIGHTNESS_Value = val;
	}
}

/* 0 ~ 100 */
void LCD_BRIGHTNESS_ApplyValue(TIM_HandleTypeDef *htim, uint32_t channel) {
	__HAL_TIM_SET_COMPARE(htim, channel, LCD_BRIGHTNESS_Value);
}
