#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "lvgl.h"
#include "ui.h"

#include "battery.h"
#include "brightness.h"
#include "power.h"

#include "fshelper.h"

void StartSystemUI(void const * argument) {
	// Lighting
	lv_task_handler();
	Brightness_SetValue(60);
	Brightness_LightUp();

	// Enable Scanning
	extern int SystemScanningEnabled;
	SystemScanningEnabled = 1;

	// Main Loop
	for (;;) {
		/* State Update */
		if (Power_GetState() == 0) {
			// Brightness
			int brightnessSliderValue;
			if (!Applications_IsRunning()) {
				brightnessSliderValue = lv_slider_get_value(ui_dropdownBrightnessSlider);
				lv_slider_set_value(ui_appDropdownBrightnessSlider, brightnessSliderValue, LV_ANIM_OFF);
			} else {
				brightnessSliderValue = lv_slider_get_value(ui_appDropdownBrightnessSlider);
				lv_slider_set_value(ui_dropdownBrightnessSlider, brightnessSliderValue, LV_ANIM_OFF);
			}
			Brightness_SetValueDirect(Brightness_CoreFunc(brightnessSliderValue));
			// Battery
			int batterySliderValue = Battery_GetPowerPercentage();
			lv_slider_set_value(ui_dropdownBatterySlider, batterySliderValue, LV_ANIM_OFF);
			lv_slider_set_value(ui_appDropdownBatterySlider, batterySliderValue, LV_ANIM_OFF);
		}

		/* Lvgl Task Handler */
		lv_task_handler();

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
