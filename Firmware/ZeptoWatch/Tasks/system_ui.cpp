#include "cmsis_os.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "tim.h"

#ifdef __cplusplus
extern "C" {
#endif

void StartSystemUI(void const * argument) {
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	HAL_TIM_Base_Start_IT(&htim2); // Lvgl Heart Beat Interrupt

	for (;;) {
		lv_task_handler();

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
