// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: Smart_Gadget

#ifndef _SMART_GADGET_UI_H
#define _SMART_GADGET_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void Up_Animation(lv_obj_t * TargetObject, int delay);
void hour_Animation(lv_obj_t * TargetObject, int delay);
void min_Animation(lv_obj_t * TargetObject, int delay);
void sec_Animation(lv_obj_t * TargetObject, int delay);
void scrolldot_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Clock(lv_event_t * e);
extern lv_obj_t * ui_Clock;
extern lv_obj_t * ui_Clock_Panel;
extern lv_obj_t * ui_Dot1;
extern lv_obj_t * ui_Dot2;
extern lv_obj_t * ui_Dot3;
extern lv_obj_t * ui_Dot4;
extern lv_obj_t * ui_Dot5;
extern lv_obj_t * ui_Dot6;
extern lv_obj_t * ui_Dot7;
extern lv_obj_t * ui_Dot8;
extern lv_obj_t * ui_Clock_Number1;
extern lv_obj_t * ui_Clock_Number2;
extern lv_obj_t * ui_Clock_Number3;
extern lv_obj_t * ui_Clock_Number4;
extern lv_obj_t * ui_Min;
extern lv_obj_t * ui_Hour;
extern lv_obj_t * ui_Sec;
extern lv_obj_t * ui_Clock_Center;
extern lv_obj_t * ui_Scrolldots;
void ui_event_Chat(lv_event_t * e);
extern lv_obj_t * ui_Chat;
extern lv_obj_t * ui_Chat_container;
extern lv_obj_t * ui_Chat_date;
extern lv_obj_t * ui_C1;
extern lv_obj_t * ui_Chat_Panel1;
extern lv_obj_t * ui_Chat1;
extern lv_obj_t * ui_Chat_Icon1;
extern lv_obj_t * ui_C2;
extern lv_obj_t * ui_Chat_Panel2;
extern lv_obj_t * ui_Chat2;
extern lv_obj_t * ui_Chat_Icon2;
extern lv_obj_t * ui_Delifered;
extern lv_obj_t * ui_C3;
extern lv_obj_t * ui_Chat_Panel3;
extern lv_obj_t * ui_Chat3;
extern lv_obj_t * ui_Chat_Icon3;
extern lv_obj_t * ui_Scrolldots2;
void ui_event_Weather(lv_event_t * e);
extern lv_obj_t * ui_Weather;
extern lv_obj_t * ui_Pary_Cloud;
extern lv_obj_t * ui_New_York;
extern lv_obj_t * ui_Cloud;
extern lv_obj_t * ui_Celsius;
extern lv_obj_t * ui_Weather_Icons;
extern lv_obj_t * ui_w1;
extern lv_obj_t * ui_w2;
extern lv_obj_t * ui_w3;
extern lv_obj_t * ui_W1_Num;
extern lv_obj_t * ui_W2_Num;
extern lv_obj_t * ui_W3_Num;
extern lv_obj_t * ui_Scrolldots4;
void ui_event_Alarm(lv_event_t * e);
extern lv_obj_t * ui_Alarm;
extern lv_obj_t * ui_Alarm_container;
extern lv_obj_t * ui_Set_alarm;
extern lv_obj_t * ui_Alarm_Comp;
extern lv_obj_t * ui_Alarm_Comp1;
extern lv_obj_t * ui_Alarm_Comp2;
extern lv_obj_t * ui_Alarm_Comp3;
extern lv_obj_t * ui_Scrolldots5;


LV_IMG_DECLARE(ui_img_pattern_png);    // assets\pattern.png
LV_IMG_DECLARE(ui_img_clock_min_png);    // assets\clock_min.png
LV_IMG_DECLARE(ui_img_clock_hour_png);    // assets\clock_hour.png
LV_IMG_DECLARE(ui_img_clock_sec_png);    // assets\clock_sec.png
LV_IMG_DECLARE(ui_img_chatbox_png);    // assets\chatbox.png
LV_IMG_DECLARE(ui_img_chatbox2_png);    // assets\chatbox2.png
LV_IMG_DECLARE(ui_img_cloud_png);    // assets\cloud.png
LV_IMG_DECLARE(ui_img_weather_1_png);    // assets\weather_1.png
LV_IMG_DECLARE(ui_img_weather_2_png);    // assets\weather_2.png
LV_IMG_DECLARE(ui_img_weather_3_png);    // assets\weather_3.png


LV_FONT_DECLARE(ui_font_Number);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
