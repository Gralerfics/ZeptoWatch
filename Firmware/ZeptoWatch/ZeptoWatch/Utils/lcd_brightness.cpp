#include "lcd_brightness.h"

uint8_t LCD_BRIGHTNESS_Value = 80;

TIM_HandleTypeDef *LCD_BRIGHTNESS_TIMHandle;
uint32_t LCD_BRIGHTNESS_TIMChannel;

void LCD_BRIGHTNESS_SetValue(uint8_t val) {
	if (LCD_BRIGHTNESS_Value >= 0 && LCD_BRIGHTNESS_Value <= 100) {
		LCD_BRIGHTNESS_Value = val;
	}
}

void LCD_BRIGHTNESS_SetTIMHandle(TIM_HandleTypeDef *htim) {
	LCD_BRIGHTNESS_TIMHandle = htim;
}

void LCD_BRIGHTNESS_SetTIMChannel(uint32_t channel) {
	LCD_BRIGHTNESS_TIMChannel = channel;
}

/* 0 ~ 100 */
void LCD_BRIGHTNESS_ApplyValue() {
	__HAL_TIM_SET_COMPARE(LCD_BRIGHTNESS_TIMHandle, LCD_BRIGHTNESS_TIMChannel, LCD_BRIGHTNESS_Value);
}
