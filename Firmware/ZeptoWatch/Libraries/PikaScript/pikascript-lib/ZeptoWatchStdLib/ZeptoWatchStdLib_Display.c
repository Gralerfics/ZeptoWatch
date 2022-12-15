#include "pikaScript.h"

#include "brightness.h"

#include "ui.h"
#include "ui_user.h"

int ZeptoWatchStdLib_Display_getBrightness(PikaObj *self) {
	return (int) Brightness_GetValue();
}

void ZeptoWatchStdLib_Display_setBrightness(PikaObj *self, int val) {
	Brightness_SetValueDirect(Brightness_CoreFunc(val));
	lv_slider_set_value(ui_dropdownBrightnessSlider, val, LV_ANIM_OFF);
	lv_slider_set_value(ui_appDropdownBrightnessSlider, val, LV_ANIM_OFF);
}
