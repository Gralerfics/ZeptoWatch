#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "lvgl.h"
#include "ui.h"
#include "brightness.h"

#include "fshelper.h"

int System_UI_IsReady = 0;

void StartSystemUI(void const * argument) {
	/* Set Page State */
	setUICurrentPage(ui_Home);

	/* Lighting */
//	System_UI_IsReady = 0;
//	while (!System_UI_IsReady) {
//		lv_task_handler();
//		osDelay(10);
//	}
	Brightness_SetValue(60);
	Brightness_LightUp();

	/* Main Loop */
	for (;;) {
		/* Lvgl Task Handler */
		extern SemaphoreHandle_t lvglMutexHandle;
		xSemaphoreTake(lvglMutexHandle, portMAX_DELAY);
		lv_task_handler();
		xSemaphoreGive(lvglMutexHandle);

		/* Delay */
		osDelay(1);

	}
}

#ifdef __cplusplus
}
#endif

/* 屏幕安回去之后的复位 */
//#include "lv_port_disp.h"
//#include "lv_port_indev.h"
//#include "cst816.h"
//  ...
//	uint8_t cnt = 0, cst_connected = 1;
//  ...
//		cnt += 1;
//		if (cnt == 255) {
//			if (CST816_Is_OnConnection() != 0) {
//				if (cst_connected == 0) {
//					lv_init();
//					lv_port_disp_init();
//					lv_port_indev_init();
//					cst_connected = 1;
//				}
//			} else {
//				cst_connected = 0;
//			}
//			cnt = 0;
//		}
//  ...
