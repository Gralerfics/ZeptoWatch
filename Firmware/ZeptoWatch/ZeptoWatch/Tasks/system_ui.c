#include "cmsis_os.h"

#include "stdio.h"

#include "lvgl.h"

#include "cst816.h"
#include "lv_port_disp.h"

#include "ui.h"

#ifdef __cplusplus
extern "C" {
#endif

void StartSystemUI(void const * argument) {
//	uint8_t cnt = 0, cst_lost = 0;
	for (;;) {
		lv_task_handler();

//		cnt += 1;
//		if (cnt == 255) {
//			lv_label_set_text(ui_Screen1_Label1, cst_lost == 0 ? "Online" : "Lost");
//			printf("%d\n", (int) CST816_Is_OnConnection());
//
//			if (CST816_Is_OnConnection()) {
//				if (cst_lost == 1) {
//					lv_port_disp_init();
//					cst_lost = 0;
//				}
//			} else {
//				cst_lost = 1;
//			}
//			cnt = 0;
//		}

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
