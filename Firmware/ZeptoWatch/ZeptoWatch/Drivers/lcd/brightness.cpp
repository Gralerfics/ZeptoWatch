#include "brightness.h"

#include "delay.h"

TIM_HandleTypeDef *Brightness_TIMHandle;
uint32_t Brightness_TIMChannel;

int Brightness_Value = 0;

void Brightness_Start(TIM_HandleTypeDef *htim, uint32_t channel) {
	Brightness_TIMHandle = htim;
	Brightness_TIMChannel = channel;
	if (Brightness_TIMHandle != nullptr && IS_TIM_CCX_INSTANCE(Brightness_TIMHandle -> Instance, Brightness_TIMChannel)) {
		HAL_TIM_PWM_Start(Brightness_TIMHandle, Brightness_TIMChannel);
	}
}

uint8_t Brightness_CoreFunc(uint8_t val) {
	// [0, 100] non-linearly mapping into [4, 100]
	return val * val * 96 / 10000 + 4;
}

void Brightness_SetValue(uint8_t val) {
	if (val >= 0 && val <= 100) {
		Brightness_Value = val;
	}
}

void Brightness_SetValueDirect(uint8_t val) {
	if (val >= 0 && val <= 100 && Brightness_TIMHandle != nullptr && IS_TIM_CCX_INSTANCE(Brightness_TIMHandle -> Instance, Brightness_TIMChannel)) {
		Brightness_Value = val;
		__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, Brightness_Value);
	}
}

uint8_t Brightness_GetValue() {
	return Brightness_Value;
}

uint8_t Brightness_GetValueDirect() {
	if (Brightness_TIMHandle != nullptr && IS_TIM_CCX_INSTANCE(Brightness_TIMHandle -> Instance, Brightness_TIMChannel)) {
		return __HAL_TIM_GET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel);
	} else {
		return 255;
	}
}

void Brightness_GoDark() {
	for (int i = 0; i < 50; i ++) {
		__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, Brightness_Value - Brightness_Value * i / 50);
		Delay_ms(8);
	}
	__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, 0);
}

void Brightness_LightUp() {
	for (int i = 0; i < 50; i ++) {
		__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, Brightness_Value * i / 50);
		Delay_ms(8);
	}
	__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, Brightness_Value);
}
