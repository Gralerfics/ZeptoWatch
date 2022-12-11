#include "cmsis_os.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

#include "common.h"

#include "applications.h"

#include "lvgl.h"
#include "ui.h"
#include "fshelper.h"

static int btn1ClickedFlag = 0, btn2ClickedFlag = 0;

void btn1Clicked(lv_event_t * e) {
	btn1ClickedFlag = 1;
}

void btn2Clicked(lv_event_t * e) {
	btn2ClickedFlag = 1;
}

void StartSystemDetecting(void const * argument) {
	char names[300] = {0};
	FS_ScanFolder("0:", names);

	lv_roller_set_options(ui_Screen1_Roller1, names, LV_ROLLER_MODE_NORMAL);

	while (1) {
		if (btn1ClickedFlag) {
			char filepath[30] = {0}, filename[30] = {0};
			lv_roller_get_selected_str(ui_Screen1_Roller1, filename, 30);
			sprintf(filepath, "0:%s", filename);

			Applications_ActivateApplication(filepath);

			btn1ClickedFlag = 0;
		}

		if (btn2ClickedFlag) {
			Applications_HaltCurrentApplication();

			btn2ClickedFlag = 0;
		}

		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
