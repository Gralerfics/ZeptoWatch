#include "common.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

#include "tim.h"
#include "oled.h"

void Main() {
	OLED_Initialize();

	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	ui_init();

	HAL_TIM_Base_Start_IT(&htim2); // Lvgl Heart Beat Interrupt

	while (true) {
		lv_task_handler();
	}
}
