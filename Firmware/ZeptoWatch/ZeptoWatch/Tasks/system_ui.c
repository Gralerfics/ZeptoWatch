#include "cmsis_os.h"

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void StartSystemUI(void const * argument) {
	for (;;) {
		lv_task_handler();

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
