#include "battery.h"

#include "adc.h"
#include "tim.h"

uint16_t Battery_ADC_Data[BAT_FILTERING_PARAM];

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

int Battery_IsCharging() {
	return HAL_GPIO_ReadPin(BAT_CHRG_R_GPIO_Port, BAT_CHRG_R_Pin) == GPIO_PIN_RESET;
}

uint16_t Battery_GetADCData() {
	uint32_t res = 0;
	for (uint8_t i = 0; i < BAT_FILTERING_PARAM; i ++) res = res + Battery_ADC_Data[i];
	return res / BAT_FILTERING_PARAM;
}

uint16_t Battery_GetVoltageTimes1000() {
	/* 高电平 (3.3V, 实测约 3.23V); 12bit 采样即分 4096 个状态; 乘 2 来自电路中两个 20k 电阻分压 */
	uint16_t res = Battery_GetADCData() * 3.23f * 1000 / 4096.0f * 2;
	if (Battery_IsCharging()) {
		uint16_t del = 10 + 190 * (res - 3300) / 700;
		res -= del; // 充电时减去
	}
	return res;
}

uint16_t Battery_GetPowerPercentage() {
	// Voltage: 3320 (3375) ~ 4025 (3975), delta = 600;
	uint16_t res = Battery_GetVoltageTimes1000();
	if (Battery_GetVoltageTimes1000() < 3375) {
		res = 0;
	} else {
		res = (Battery_GetVoltageTimes1000() - 3375) / 6;
	}
	return res > 100 ? 100 : res;
}
