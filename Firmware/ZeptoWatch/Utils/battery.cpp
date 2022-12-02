#include "battery.h"

#include "adc.h"
#include "tim.h"

uint16_t Battery_ADC_Data[1];

void Battery_Init() {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_BAT_CHRG_R_CLK_ENABLE();

	GPIO_InitStruct.Pin = BAT_CHRG_R_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BAT_CHRG_R_GPIO_Port, &GPIO_InitStruct);

//	__HAL_ADC_ENABLE(&hadc1);
//	HAL_DMA_Start(hadc1.DMA_Handle, (uint32_t) &hadc1.Instance -> DR, (uint32_t) &Battery_ADC_Data, 1);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &Battery_ADC_Data, 1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
}

int Battery_IsCharging() {
	return HAL_GPIO_ReadPin(BAT_CHRG_R_GPIO_Port, BAT_CHRG_R_Pin) == GPIO_PIN_RESET;
}

uint16_t Battery_GetADCData() {
	return Battery_ADC_Data[0];
}

uint16_t Battery_GetVoltageTimes1000() {
	uint16_t res = Battery_ADC_Data[0] * 3.3f * 1000 / 4096.0f * 2; // * 2 来自分压
	if (Battery_IsCharging()) res -= 2; // 充电时减去
	return res;
}

uint16_t Battery_GetPowerPercentage() {
	uint16_t res = (Battery_GetVoltageTimes1000() - 3400) / 8;
	res = res > 100 ? 100 : res;
	return res;
}
