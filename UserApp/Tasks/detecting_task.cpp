#include "lcd_brightness.h"
#include "cmsis_os.h"

#include "tim.h"
#include "ui.h"

/* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
#ifdef __cplusplus
extern "C" {
#endif

void StartDetectingTask(void const * argument) {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // ENABLE LCD_BLK (TIM3) PWM Channel

	while (true) {
		LCD_BRIGHTNESS_SetValue(lv_arc_get_value(ui_Home_Arc2));
		LCD_BRIGHTNESS_ApplyValue(&htim3, TIM_CHANNEL_1);

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif