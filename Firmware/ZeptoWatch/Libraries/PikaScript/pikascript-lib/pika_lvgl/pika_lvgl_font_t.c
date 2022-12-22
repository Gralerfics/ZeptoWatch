#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../../lvgl.h"
#endif

#ifdef PIKASCRIPT

#include "pika_lvgl.h"
#include "pika_lvgl_font_t.h"
#include "pika_lvgl_FONT.h"

void pika_lvgl_font_t___init__(PikaObj *self) {
	lv_font_t *lv_font = lv_font_default();
	obj_setPtr(self, "lv_font", &lv_font);
}

void pika_lvgl_FONT___init__(PikaObj *self) {
	PikaObj *font = newNormalObj(New_pika_lvgl_font_t);
#if LV_FONT_MONTSERRAT_8
	obj_setPtr(font, "lv_font", &lv_font_montserrat_8);
	obj_setPtr(self, "MONTSERRAT_8", font);
#endif
#if LV_FONT_MONTSERRAT_10
	obj_setPtr(font, "lv_font", &lv_font_montserrat_10);
	obj_setPtr(self, "MONTSERRAT_10", font);
#endif
#if LV_FONT_MONTSERRAT_12
	obj_setPtr(font, "lv_font", &lv_font_montserrat_12);
	obj_setPtr(self, "MONTSERRAT_12", font);
#endif
#if LV_FONT_MONTSERRAT_14
	obj_setPtr(font, "lv_font", &lv_font_montserrat_14);
	obj_setPtr(self, "MONTSERRAT_14", font);
#endif
#if LV_FONT_MONTSERRAT_1
	obj_setPtr(font, "lv_font", &lv_font_montserrat_16);
	obj_setPtr(self, "MONTSERRAT_16", font);
#endif
#if LV_FONT_MONTSERRAT_18
	obj_setPtr(font, "lv_font", &lv_font_montserrat_18);
	obj_setPtr(self, "MONTSERRAT_18", font);
#endif
#if LV_FONT_MONTSERRAT_20
	obj_setPtr(font, "lv_font", &lv_font_montserrat_20);
	obj_setPtr(self, "MONTSERRAT_20", font);
#endif
#if LV_FONT_MONTSERRAT_22
	obj_setPtr(font, "lv_font", &lv_font_montserrat_22);
	obj_setPtr(self, "MONTSERRAT_22", font);
#endif
#if LV_FONT_MONTSERRAT_24
	obj_setPtr(font, "lv_font", &lv_font_montserrat_24);
	obj_setPtr(self, "MONTSERRAT_24", font);
#endif
#if LV_FONT_MONTSERRAT_26
	obj_setPtr(font, "lv_font", &lv_font_montserrat_26);
	obj_setPtr(self, "MONTSERRAT_26", font);
#endif
#if LV_FONT_MONTSERRAT_28
	obj_setPtr(font, "lv_font", &lv_font_montserrat_28);
	obj_setPtr(self, "MONTSERRAT_28", font);
#endif
#if LV_FONT_MONTSERRAT_30
	obj_setPtr(font, "lv_font", &lv_font_montserrat_30);
	obj_setPtr(self, "MONTSERRAT_30", font);
#endif
#if LV_FONT_MONTSERRAT_32
	obj_setPtr(font, "lv_font", &lv_font_montserrat_32);
	obj_setPtr(self, "MONTSERRAT_32", font);
#endif
#if LV_FONT_MONTSERRAT_34
	obj_setPtr(font, "lv_font", &lv_font_montserrat_34);
	obj_setPtr(self, "MONTSERRAT_34", font);
#endif
#if LV_FONT_MONTSERRAT_36
	obj_setPtr(font, "lv_font", &lv_font_montserrat_36);
	obj_setPtr(self, "MONTSERRAT_36", font);
#endif
#if LV_FONT_MONTSERRAT_38
	obj_setPtr(font, "lv_font", &lv_font_montserrat_38);
	obj_setPtr(self, "MONTSERRAT_38", font);
#endif
#if LV_FONT_MONTSERRAT_40
	obj_setPtr(font, "lv_font", &lv_font_montserrat_40);
	obj_setPtr(self, "MONTSERRAT_40", font);
#endif
#if LV_FONT_MONTSERRAT_42
	obj_setPtr(font, "lv_font", &lv_font_montserrat_42);
	obj_setPtr(self, "MONTSERRAT_42", font);
#endif
#if LV_FONT_MONTSERRAT_44
	obj_setPtr(font, "lv_font", &lv_font_montserrat_44);
	obj_setPtr(self, "MONTSERRAT_44", font);
#endif
#if LV_FONT_MONTSERRAT_46
	obj_setPtr(font, "lv_font", &lv_font_montserrat_46);
	obj_setPtr(self, "MONTSERRAT_46", font);
#endif
#if LV_FONT_MONTSERRAT_48
	obj_setPtr(font, "lv_font", &lv_font_montserrat_48);
	obj_setPtr(self, "MONTSERRAT_48", font);
#endif
}

#endif
