#include "vibrator.h"

TIM_HandleTypeDef *Vibrator_TIMHandle_PWM;
uint32_t Vibrator_TIMChannel;

void Vibrator_Initialize(TIM_HandleTypeDef *htim_p, uint32_t channel) {
	Vibrator_TIMHandle_PWM = htim_p;
	Vibrator_TIMChannel = channel;
	if (Vibrator_TIMHandle_PWM != nullptr && IS_TIM_CCX_INSTANCE(Vibrator_TIMHandle_PWM -> Instance, Vibrator_TIMChannel)) {
		__HAL_TIM_SET_COMPARE(Vibrator_TIMHandle_PWM, Vibrator_TIMChannel, 0);
		HAL_TIM_PWM_Start(Vibrator_TIMHandle_PWM, Vibrator_TIMChannel);
	}
}

void Vibrator_Assert(int ms, int pulse) {
	if (pulse < 0 || pulse > 100) return;
	if (Vibrator_TIMHandle_PWM != nullptr && IS_TIM_CCX_INSTANCE(Vibrator_TIMHandle_PWM -> Instance, Vibrator_TIMChannel)) {
		__HAL_TIM_SET_COMPARE(Vibrator_TIMHandle_PWM, Vibrator_TIMChannel, pulse);
		HAL_TIM_PWM_Start(Vibrator_TIMHandle_PWM, Vibrator_TIMChannel);
		osDelay(ms);
		Vibrator_Stop();
	}
}

void Vibrator_Stop() {
	if (Vibrator_TIMHandle_PWM == nullptr) return;
	__HAL_TIM_SET_COMPARE(Vibrator_TIMHandle_PWM, Vibrator_TIMChannel, 0);
}
