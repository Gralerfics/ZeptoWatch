#include "brightness.h"

TIM_HandleTypeDef *Brightness_TIMHandle;
uint32_t Brightness_TIMChannel;

void Brightness_SetTIMHandle(TIM_HandleTypeDef *htim) {
	Brightness_TIMHandle = htim;
}

void Brightness_SetTIMChannel(uint32_t channel) {
	Brightness_TIMChannel = channel;
}

void Brightness_Start() {
	if (Brightness_TIMHandle != nullptr && IS_TIM_CCX_INSTANCE(Brightness_TIMHandle -> Instance, Brightness_TIMChannel)) {
		HAL_TIM_PWM_Start(Brightness_TIMHandle, Brightness_TIMChannel);
	}
}

void Brightness_SetValue(uint8_t val) {
	if (val >= 0 && val <= 100) {
		__HAL_TIM_SET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel, val);
	}
}

uint8_t Brightness_GetValue() {
	if (Brightness_TIMHandle != nullptr && IS_TIM_CCX_INSTANCE(Brightness_TIMHandle -> Instance, Brightness_TIMChannel)) {
		return __HAL_TIM_GET_COMPARE(Brightness_TIMHandle, Brightness_TIMChannel);
	} else {
		return 255;
	}
}
