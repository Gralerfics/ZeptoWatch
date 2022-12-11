#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

#include "lvgl.h"
#include "ui.h"

void StartSystemUI(void const * argument) {
	extern int btn1ClickedFlag, btn2ClickedFlag;

	for (;;) {
		/* Lvgl 任务处理 */
		lv_task_handler();

		/* 事件处理 */
		if (btn1ClickedFlag) {
			char filepath[30] = {0}, filename[30] = {0};
			lv_roller_get_selected_str(ui_roller, filename, 30);
			sprintf(filepath, "0:%s", filename);
			Applications_ActivateApplication(filepath);
			btn1ClickedFlag = 0;
		}
		if (btn2ClickedFlag) {
			Applications_HaltApplication();
			btn2ClickedFlag = 0;
		}

		/* 延时 */
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
