#include "cmsis_os.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

#include "common.h"

#include "lvgl.h"
#include "ui.h"

#include "applications.h"
#include "battery.h"
#include "power.h"
#include "brightness.h"

lv_chart_series_t *series = NULL;

void StartSystemDetecting(void const * argument) {
//	int cnt = 0;
	while (1) {
		/* State Update */
		if (Power_GetState() == 0) {
			/* Brightness */
			int brightnessSliderValue;
			if (!Applications_IsRunning()) {
				brightnessSliderValue = lv_slider_get_value(ui_dropdownBrightnessSlider);
				lv_slider_set_value(ui_appDropdownBrightnessSlider, brightnessSliderValue, LV_ANIM_OFF);
			} else {
				brightnessSliderValue = lv_slider_get_value(ui_appDropdownBrightnessSlider);
				lv_slider_set_value(ui_dropdownBrightnessSlider, brightnessSliderValue, LV_ANIM_OFF);
			}
			Brightness_SetValueDirect(Brightness_CoreFunc(brightnessSliderValue));

			/* Battery */
//			if (cnt ++ >= 500) {
				int batterySliderValue = Battery_GetPowerPercentage();
//				if (!Battery_IsCharging() && batterySliderValue < 0) {
//					Power_Standby();
//				} else {
					lv_slider_set_value(ui_dropdownBatterySlider, batterySliderValue, LV_ANIM_OFF);
					lv_slider_set_value(ui_appDropdownBatterySlider, batterySliderValue, LV_ANIM_OFF);
//				}
//				cnt = 0;
//			}
		}
		osDelay(5);
	}
}

#ifdef __cplusplus
}
#endif
