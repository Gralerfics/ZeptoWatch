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

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Screen1_Label1;
extern lv_obj_t * ui_Screen1_Roller1;
void ui_event_Screen1_Button1(lv_event_t * e);
extern lv_obj_t * ui_Screen1_Button1;
extern lv_obj_t * ui_Screen2;
void ui_event_Screen2_Button2(lv_event_t * e);
extern lv_obj_t * ui_Screen2_Button2;
extern lv_obj_t * ui_Screen2_Label1;

void btn1Clicked(lv_event_t * e);
void btn2Clicked(lv_event_t * e);





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
