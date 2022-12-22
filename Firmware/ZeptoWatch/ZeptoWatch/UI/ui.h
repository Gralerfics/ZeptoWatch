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
void applicationsEntering_Animation(lv_obj_t * TargetObject, int delay);
void applicationsLeaving_Animation(lv_obj_t * TargetObject, int delay);
void appRefreshing_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_secPtr;
extern lv_obj_t * ui_minPtr;
extern lv_obj_t * ui_hourPtr;
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
void ui_event_Applications(lv_event_t * e);
extern lv_obj_t * ui_Applications;
extern lv_obj_t * ui_applicationsPanel;
extern lv_obj_t * ui_applicationsLabel;
extern lv_obj_t * ui_applicationsList;
extern lv_obj_t * ui_appRefreshIcon;
void ui_event_Appfield(lv_event_t * e);
extern lv_obj_t * ui_Appfield;
extern lv_obj_t * ui_Shutdown;
extern lv_obj_t * ui_shundownPanel;
extern lv_obj_t * ui_shutdownLabel;
void ui_event_shutdownConfirmBtn(lv_event_t * e);
extern lv_obj_t * ui_shutdownConfirmBtn;
void ui_event_shutdownBackBtn(lv_event_t * e);
extern lv_obj_t * ui_shutdownBackBtn;
extern lv_obj_t * ui_AppDropdown;
extern lv_obj_t * ui_appDropdownPanel;
extern lv_obj_t * ui_appDropdownTimeLabel;
extern lv_obj_t * ui_appDropdownBatterySlider;
extern lv_obj_t * ui_appDropdownBrightnessSlider;
void ui_event_appDropdownBtn(lv_event_t * e);
extern lv_obj_t * ui_appDropdownBtn;
void ui_event_appDropdownBackBtn(lv_event_t * e);
extern lv_obj_t * ui_appDropdownBackBtn;

void ui_event_Settings(lv_event_t * e);
extern lv_obj_t * ui_settingsBkPanel;
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_settingsLabel;
extern lv_obj_t * ui_settingsPanel;
extern lv_obj_t * ui_settingsTimeLabel;
void ui_event_settingsTimeBtn(lv_event_t * e);
extern lv_obj_t * ui_settingsTimeBtn;
void ui_event_rollers(lv_event_t * e);
extern lv_obj_t * ui_rolHour;
extern lv_obj_t * ui_rolMin;
extern lv_obj_t * ui_rolSec;
extern lv_obj_t * ui_settingsDateLabel;
void ui_event_settingsDateBtn(lv_event_t * e);
extern lv_obj_t * ui_settingsDateBtn;
extern lv_obj_t * ui_rolYear;
extern lv_obj_t * ui_rolMon;
extern lv_obj_t * ui_rolDay;
extern lv_obj_t * ui_settingsBuiltInAppLabel;
void ui_event_settingsEnBulSwt(lv_event_t * e);
extern lv_obj_t * ui_settingsEnBulSwt;

LV_IMG_DECLARE(ui_img_clock_sec_png);    // assets\clock_sec.png
LV_IMG_DECLARE(ui_img_clock_min_png);    // assets\clock_min.png
LV_IMG_DECLARE(ui_img_clock_hour_png);    // assets\clock_hour.png
LV_IMG_DECLARE(ui_img_battery_png);    // assets\battery.png
LV_IMG_DECLARE(ui_img_brightness_png);    // assets\brightness.png
LV_IMG_DECLARE(ui_img_home_png);    // assets\home.png
LV_IMG_DECLARE(ui_img_undo_png);    // assets\undo.png
LV_IMG_DECLARE(ui_img_power_png);    // assets\power.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
