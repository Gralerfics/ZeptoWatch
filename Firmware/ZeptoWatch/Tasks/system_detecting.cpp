#include "cmsis_os.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

void StartSystemDetecting(void const * argument) {

	while (true) {

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif

//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // ENABLE LCD_BLK (TIM3) PWM Channel
//	LCD_BRIGHTNESS_SetTIMHandle(&htim3);
//	LCD_BRIGHTNESS_SetTIMChannel(TIM_CHANNEL_1);
//
//	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); // ENABLE MOTOR (TIM4) PWM Channel
//	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
