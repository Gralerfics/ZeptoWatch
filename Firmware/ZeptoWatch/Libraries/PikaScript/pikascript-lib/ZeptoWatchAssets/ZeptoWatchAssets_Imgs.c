#include "pikaScript.h"

#include "pika_lvgl_img_dsc_t.h"
#include "ui_user.h"

void ZeptoWatchAssets_Imgs___init__(PikaObj *self) {
	PikaObj *img = newNormalObj(New_pika_lvgl_img_dsc_t);

	obj_setStruct(img, "img_dsc", ui_img_woodenf_png);
	obj_setPtr(self, "WOODENF", img);
}
