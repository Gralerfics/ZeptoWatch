#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

#include "lvgl.h"
#include "ui.h"

#include "battery.h"
#include "brightness.h"
#include "power.h"

void StartSystemUI(void const * argument) {
//	extern int btn1ClickedFlag, btn2ClickedFlag;

	for (;;) {
		/* 状态更新 */
		if (Power_GetState() == 0) {
			int brightnessSliderValue = lv_slider_get_value(ui_dropdownBrightnessSlider);
			Brightness_SetValue(brightnessSliderValue * brightnessSliderValue * 99 / 10000 + 1);

			lv_slider_set_value(ui_dropdownBatterySlider, Battery_GetPowerPercentage(), LV_ANIM_OFF);
		}

		/* 事件处理 */
//		if (btn1ClickedFlag) {
//			char filepath[30] = {0}, filename[30] = {0};
//			lv_roller_get_selected_str(ui_roller, filename, 30);
//			sprintf(filepath, "0:%s", filename);
//			lv_label_set_text(ui_applabel, filepath);
//			Applications_ActivateApplication(filepath);
//			btn1ClickedFlag = 0;
//		}
//		if (btn2ClickedFlag) {
//			Applications_HaltApplication();
//			btn2ClickedFlag = 0;
//		}

		/* Lvgl 任务处理 */
		lv_task_handler();

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
