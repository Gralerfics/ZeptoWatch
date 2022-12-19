#include "battery.h"

#include "adc.h"
#include "tim.h"

uint16_t Battery_ADC_Data[BAT_FILTERING_PARAM];

#define BATTERY_ADC_LOW_TH 2110						// limit: ~2080 [2080]
#define BATTERY_ADC_HIGH_TH 2290					// limit: ~2300 [2600]

void Battery_Init() {
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	__HAL_RCC_BAT_CHRG_R_CLK_ENABLE();

	GPIO_InitStructure.Pin = BAT_CHRG_R_Pin;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BAT_CHRG_R_GPIO_Port, &GPIO_InitStructure);
}

void Battery_StartSampling() {
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &Battery_ADC_Data, 10);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
}

void Battery_StopSampling() {
	HAL_ADC_Stop_DMA(&hadc1);
	HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
}

int Battery_IsCharging() {
	return HAL_GPIO_ReadPin(BAT_CHRG_R_GPIO_Port, BAT_CHRG_R_Pin) == GPIO_PIN_RESET;
}

uint16_t Battery_GetADCData() {
	uint32_t res = 0;
	for (uint8_t i = 0; i < BAT_FILTERING_PARAM; i ++) res = res + Battery_ADC_Data[i];
	return res / BAT_FILTERING_PARAM;
}

uint16_t Battery_GetPowerPercentage() {
	uint16_t res = Battery_GetADCData();
	if (res < 2150) {
		res = 0;
	} else {
		res = (res - 2150) / 6;
	}
	return res > 100 ? 100 : res;
}
