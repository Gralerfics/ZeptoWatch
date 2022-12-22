#include "battery.h"

#include "adc.h"
#include "tim.h"

uint16_t Battery_ADC_Data[BAT_FILTERING_PARAM];

//#define BATTERY_ADC_HIGH_LIMIT_CHARGE_TH 2580
//#define BATTERY_ADC_HIGH_TH 2410					// limit: ~2480 [2580]
//#define BATTERY_ADC_LOW_TH 2150					// limit: ~2080 [2080]
//#define BATTERY_ADC_DELTA 100
//#define BATTERY_ADC_SHUTDOWN_TH 2120
//#define BATTERY_ADC_LOW_LIMIT_TH 2080

#define BATTERY_ADC_HIGH_LIMIT_CHARGE_TH 3060
#define BATTERY_ADC_HIGH_TH 2880					// limit: 2900 [3060]
#define BATTERY_ADC_LOW_TH 2750						// limit: ~2680 [2680]
#define BATTERY_ADC_DELTA 160
#define BATTERY_ADC_SHUTDOWN_TH 2720
#define BATTERY_ADC_LOW_LIMIT_TH 2680

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

int Battery_GetPowerPercentage() {
	int res = Battery_GetADCData();
	if (Battery_IsCharging()) {
		res = res - BATTERY_ADC_DELTA * (res - BATTERY_ADC_LOW_LIMIT_TH) / (BATTERY_ADC_HIGH_LIMIT_CHARGE_TH - BATTERY_ADC_LOW_LIMIT_TH);
	}
	if (res <= BATTERY_ADC_LOW_TH) {
		if (res < BATTERY_ADC_SHUTDOWN_TH) {
			res = -1;
		} else {
			res = 0;
		}
	} else if (res >= BATTERY_ADC_HIGH_TH){
		res = 100;
	} else {
		res = 100 * (res - BATTERY_ADC_LOW_TH) / (BATTERY_ADC_HIGH_TH - BATTERY_ADC_LOW_TH);
	}
	return res;
}
