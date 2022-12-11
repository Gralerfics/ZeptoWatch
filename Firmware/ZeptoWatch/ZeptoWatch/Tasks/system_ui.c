#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "lvgl.h"

//#include "lv_port_disp.h"
//#include "lv_port_indev.h"
//#include "cst816.h"

void StartSystemUI(void const * argument) {
	uint8_t cnt = 0, cst_connected = 1;
	for (;;) {
		/* Lvgl 事件处理 */
		lv_task_handler();

		/* 屏幕安回去之后的复位 */
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

		/* 延时 */
		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
