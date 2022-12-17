#include "pikaScript.h"

#include "brightness.h"
#include "pika_lvgl_lv_obj.h"

#include "ui.h"

PikaObj* ZeptoWatchStdLib_Display_getField(PikaObj *self) {
	PikaObj* new_obj = newNormalObj(New_pika_lvgl_lv_obj);
	lv_obj_t* lv_obj = ui_Appfield;
	obj_setPtr(new_obj, "lv_obj", lv_obj);
	return new_obj;
}

int ZeptoWatchStdLib_Display_getBrightness(PikaObj *self) {
	return (int) Brightness_GetValue();
}

void ZeptoWatchStdLib_Display_setBrightness(PikaObj *self, int val) {
	Brightness_SetValueDirect(Brightness_CoreFunc(val));
	lv_slider_set_value(ui_dropdownBrightnessSlider, val, LV_ANIM_OFF);
	lv_slider_set_value(ui_appDropdownBrightnessSlider, val, LV_ANIM_OFF);
}
