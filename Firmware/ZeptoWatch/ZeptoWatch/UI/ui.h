// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: systemui

#ifndef _SYSTEMUI_UI_H
#define _SYSTEMUI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

void dropdownDropping_Animation(lv_obj_t * TargetObject, int delay);
void dropdownLeaving_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_secPtr;
extern lv_obj_t * ui_minPtr;
extern lv_obj_t * ui_hourptr;
extern lv_obj_t * ui_ptrDot;
extern lv_obj_t * ui_clockDot12;
extern lv_obj_t * ui_clockDot6;
extern lv_obj_t * ui_clockDot3;
extern lv_obj_t * ui_clockDot9;
extern lv_obj_t * ui_Dropdown;
extern lv_obj_t * ui_dropdownPanel;
extern lv_obj_t * ui_dropdownTimeLabel;
extern lv_obj_t * ui_dropdownBatterySlider;
extern lv_obj_t * ui_dropdownBrightnessSlider;
void ui_event_dropdownBtn(lv_event_t * e);
extern lv_obj_t * ui_dropdownBtn;
extern lv_obj_t * ui_Applications;
extern lv_obj_t * ui_Appfield;
extern lv_obj_t * ui_Shutdown;
extern lv_obj_t * ui_shutdownLabel;
extern lv_obj_t * ui_shutdownConfirmBtn;
extern lv_obj_t * ui_shutdownBackBtn;


LV_IMG_DECLARE(ui_img_clock_sec_png);    // assets\clock_sec.png
LV_IMG_DECLARE(ui_img_clock_min_png);    // assets\clock_min.png
LV_IMG_DECLARE(ui_img_clock_hour_png);    // assets\clock_hour.png
LV_IMG_DECLARE(ui_img_electric_png);    // assets\electric.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
