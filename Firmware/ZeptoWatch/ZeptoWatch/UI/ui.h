// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: est

#ifndef _EST_UI_H
#define _EST_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_Main;
extern lv_obj_t * ui_info;
extern lv_obj_t * ui_roller;
void ui_event_exeBtn(lv_event_t * e);
extern lv_obj_t * ui_exeBtn;
extern lv_obj_t * ui_chart;
extern lv_obj_t * ui_Application;
void ui_event_backBtn(lv_event_t * e);
extern lv_obj_t * ui_backBtn;
extern lv_obj_t * ui_applabel;

void btn1Clicked(lv_event_t * e);
void btn2Clicked(lv_event_t * e);





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
