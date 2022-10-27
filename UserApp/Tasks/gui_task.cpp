#include "cmsis_os.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"
#include "tim.h"

#ifdef __cplusplus
extern "C" {
#endif

void StartLvglTask(void const * argument) {
	/* USER CODE BEGIN StartLvglTask */
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	ui_init();

	HAL_TIM_Base_Start_IT(&htim2); // Lvgl Heart Beat Interrupt

	/* Infinite loop */
	for (;;) {
		lv_task_handler();

		osDelay(1);
	}
	/* USER CODE END StartLvglTask */
}

#ifdef __cplusplus
}
#endif
