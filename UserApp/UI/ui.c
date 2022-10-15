// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: Smart_Gadget

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

#include "rtc_handler.h"

///////////////////// VARIABLES ////////////////////
void Up_Animation(lv_obj_t * TargetObject, int delay);
void hour_Animation(lv_obj_t * TargetObject, int delay);
void min_Animation(lv_obj_t * TargetObject, int delay);
void sec_Animation(lv_obj_t * TargetObject, int delay);
void scrolldot_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Clock(lv_event_t * e);
lv_obj_t * ui_Clock;
lv_obj_t * ui_Clock_Panel;
lv_obj_t * ui_Dot1;
lv_obj_t * ui_Dot2;
lv_obj_t * ui_Dot3;
lv_obj_t * ui_Dot4;
lv_obj_t * ui_Dot5;
lv_obj_t * ui_Dot6;
lv_obj_t * ui_Dot7;
lv_obj_t * ui_Dot8;
lv_obj_t * ui_Clock_Number1;
lv_obj_t * ui_Clock_Number2;
lv_obj_t * ui_Clock_Number3;
lv_obj_t * ui_Clock_Number4;
lv_obj_t * ui_Min;
lv_obj_t * ui_Hour;
lv_obj_t * ui_Sec;
lv_obj_t * ui_Clock_Center;
lv_obj_t * ui_Scrolldots;
void ui_event_Chat(lv_event_t * e);
lv_obj_t * ui_Chat;
lv_obj_t * ui_Chat_container;
lv_obj_t * ui_Chat_date;
lv_obj_t * ui_C1;
lv_obj_t * ui_Chat_Panel1;
lv_obj_t * ui_Chat1;
lv_obj_t * ui_Chat_Icon1;
lv_obj_t * ui_C2;
lv_obj_t * ui_Chat_Panel2;
lv_obj_t * ui_Chat2;
lv_obj_t * ui_Chat_Icon2;
lv_obj_t * ui_Delifered;
lv_obj_t * ui_C3;
lv_obj_t * ui_Chat_Panel3;
lv_obj_t * ui_Chat3;
lv_obj_t * ui_Chat_Icon3;
lv_obj_t * ui_Scrolldots2;
void ui_event_Weather(lv_event_t * e);
lv_obj_t * ui_Weather;
lv_obj_t * ui_Pary_Cloud;
lv_obj_t * ui_New_York;
lv_obj_t * ui_Cloud;
lv_obj_t * ui_Celsius;
lv_obj_t * ui_Weather_Icons;
lv_obj_t * ui_w1;
lv_obj_t * ui_w2;
lv_obj_t * ui_w3;
lv_obj_t * ui_W1_Num;
lv_obj_t * ui_W2_Num;
lv_obj_t * ui_W3_Num;
lv_obj_t * ui_Scrolldots4;
void ui_event_Alarm(lv_event_t * e);
lv_obj_t * ui_Alarm;
lv_obj_t * ui_Alarm_container;
lv_obj_t * ui_Set_alarm;
lv_obj_t * ui_Alarm_Comp;
lv_obj_t * ui_Alarm_Comp1;
lv_obj_t * ui_Alarm_Comp2;
lv_obj_t * ui_Alarm_Comp3;
lv_obj_t * ui_Scrolldots5;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void Step_Animation(lv_obj_t * TargetObject, int startAngle, int endAngle) {
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, 100);
	lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
	lv_anim_set_values(&PropertyAnimation_0, startAngle, endAngle);
	lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
	lv_anim_set_delay(&PropertyAnimation_0, 0);
	lv_anim_set_playback_time(&PropertyAnimation_0, 0);
	lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
	lv_anim_set_early_apply(&PropertyAnimation_0, false);
	lv_anim_start(&PropertyAnimation_0);
}

void Up_Animation(lv_obj_t * TargetObject, int delay) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -50, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 200);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);
}

void hour_Animation(lv_obj_t * TargetObject, int delay) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, RTC_LVGL_GetHourRotation());
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 100);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);
}

void min_Animation(lv_obj_t * TargetObject, int delay) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, RTC_LVGL_GetMinuteRotation());
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 200);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);
}

void sec_Animation(lv_obj_t * TargetObject, int delay) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, RTC_LVGL_GetSecondRotation());
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);
}

void scrolldot_Animation(lv_obj_t * TargetObject, int delay) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 30, -8);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);
}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Clock(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Up_Animation(ui_Clock_Panel, 100);
        scrolldot_Animation(ui_Scrolldots, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Alarm, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
		RTC_Update();
        hour_Animation(ui_Hour, 0);
        min_Animation(ui_Min, 0);
        sec_Animation(ui_Sec, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Chat, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}

void ui_event_Chat(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Up_Animation(ui_Chat_date, 100);
        Up_Animation(ui_C1, 200);
        Up_Animation(ui_C2, 300);
        Up_Animation(ui_C3, 400);
        scrolldot_Animation(ui_Scrolldots2, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Weather, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}

void ui_event_Weather(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Up_Animation(ui_Cloud, 100);
        Up_Animation(ui_Pary_Cloud, 200);
        Up_Animation(ui_Celsius, 300);
        Up_Animation(ui_New_York, 400);
        Up_Animation(ui_Weather_Icons, 300);
        scrolldot_Animation(ui_Scrolldots4, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Chat, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Alarm, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}

void ui_event_Alarm(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Up_Animation(ui_Set_alarm, 100);
        Up_Animation(ui_Alarm_Comp, 200);
        Up_Animation(ui_Alarm_Comp1, 300);
        Up_Animation(ui_Alarm_Comp2, 400);
        Up_Animation(ui_Alarm_Comp3, 500);
        scrolldot_Animation(ui_Scrolldots5, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Weather, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Clock_screen_init(void) {
    ui_Clock = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Clock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Clock, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Clock, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_Panel = lv_obj_create(ui_Clock);
    lv_obj_set_width(ui_Clock_Panel, 180);
    lv_obj_set_height(ui_Clock_Panel, 180);
    lv_obj_set_align(ui_Clock_Panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Clock_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Clock_Panel, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Clock_Panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Clock_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dot1 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot1, -40);
    lv_obj_set_y(ui_Dot1, 15);
    lv_obj_set_align(ui_Dot1, LV_ALIGN_TOP_RIGHT);

    ui_Dot2 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot2, -10);
    lv_obj_set_y(ui_Dot2, 50);

    ui_Dot3 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot3, 40);
    lv_obj_set_y(ui_Dot3, 15);
    lv_obj_set_align(ui_Dot3, LV_ALIGN_TOP_LEFT);

    ui_Dot4 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot4, 10);
    lv_obj_set_y(ui_Dot4, 50);
    lv_obj_set_align(ui_Dot4, LV_ALIGN_TOP_LEFT);

    ui_Dot5 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot5, 10);
    lv_obj_set_y(ui_Dot5, -50);
    lv_obj_set_align(ui_Dot5, LV_ALIGN_BOTTOM_LEFT);

    ui_Dot6 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot6, 40);
    lv_obj_set_y(ui_Dot6, -15);
    lv_obj_set_align(ui_Dot6, LV_ALIGN_BOTTOM_LEFT);

    ui_Dot7 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot7, -10);
    lv_obj_set_y(ui_Dot7, -50);
    lv_obj_set_align(ui_Dot7, LV_ALIGN_BOTTOM_RIGHT);

    ui_Dot8 = ui_Clock_Dot_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Dot8, -40);
    lv_obj_set_y(ui_Dot8, -15);
    lv_obj_set_align(ui_Dot8, LV_ALIGN_BOTTOM_RIGHT);

    ui_Clock_Number1 = ui_Small_Label_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Clock_Number1, 0);
    lv_obj_set_y(ui_Clock_Number1, 0);

    ui_Clock_Number2 = ui_Small_Label_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Clock_Number2, 0);
    lv_obj_set_y(ui_Clock_Number2, 0);
    lv_obj_set_align(ui_Clock_Number2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Clock_Number2, "6");

    ui_Clock_Number3 = ui_Small_Label_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Clock_Number3, 0);
    lv_obj_set_y(ui_Clock_Number3, 0);
    lv_obj_set_align(ui_Clock_Number3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Clock_Number3, "9");

    ui_Clock_Number4 = ui_Small_Label_create(ui_Clock_Panel);
    lv_obj_set_x(ui_Clock_Number4, 0);
    lv_obj_set_y(ui_Clock_Number4, 0);
    lv_obj_set_align(ui_Clock_Number4, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Clock_Number4, "3");

    ui_Min = lv_img_create(ui_Clock_Panel);
    lv_img_set_src(ui_Min, &ui_img_clock_min_png);
    lv_obj_set_width(ui_Min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Min, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Min, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Min, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Hour = lv_img_create(ui_Clock_Panel);
    lv_img_set_src(ui_Hour, &ui_img_clock_hour_png);
    lv_obj_set_width(ui_Hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Hour, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Hour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Hour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Sec = lv_img_create(ui_Clock_Panel);
    lv_img_set_src(ui_Sec, &ui_img_clock_sec_png);
    lv_obj_set_width(ui_Sec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Sec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Sec, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Sec, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Sec, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Clock_Center = lv_obj_create(ui_Clock_Panel);
    lv_obj_set_width(ui_Clock_Center, 8);
    lv_obj_set_height(ui_Clock_Center, 8);
    lv_obj_set_align(ui_Clock_Center, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Clock_Center, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Clock_Center, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Clock_Center, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Clock_Center, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Clock_Center, lv_color_hex(0x1937D2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Clock_Center, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Clock_Center, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Scrolldots = ui_Scrolldots_create(ui_Clock);
    lv_obj_set_x(ui_Scrolldots, 0);
    lv_obj_set_y(ui_Scrolldots, -8);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots, UI_COMP_SCROLLDOTS_D1), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots, UI_COMP_SCROLLDOTS_D1), 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Clock, ui_event_Clock, LV_EVENT_ALL, NULL);
}

void ui_Chat_screen_init(void) {
    ui_Chat = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Chat, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Chat, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Chat, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_container = lv_obj_create(ui_Chat);
    lv_obj_set_width(ui_Chat_container, lv_pct(100));
    lv_obj_set_height(ui_Chat_container, lv_pct(100));
    lv_obj_set_align(ui_Chat_container, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Chat_container, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chat_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_date = ui_Small_Label_create(ui_Chat_container);
    lv_obj_set_x(ui_Chat_date, 0);
    lv_obj_set_y(ui_Chat_date, 17);
    lv_obj_set_align(ui_Chat_date, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Chat_date, "Yesterday 07:25");
    lv_obj_set_style_text_color(ui_Chat_date, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chat_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_C1 = lv_obj_create(ui_Chat_container);
    lv_obj_set_height(ui_C1, 100);
    lv_obj_set_width(ui_C1, lv_pct(100));
    lv_obj_set_x(ui_C1, 0);
    lv_obj_set_y(ui_C1, 60);
    lv_obj_clear_flag(ui_C1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_C1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_C1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_C1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_C1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_C1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_C1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Panel1 = lv_obj_create(ui_C1);
    lv_obj_set_width(ui_Chat_Panel1, 169);
    lv_obj_set_height(ui_Chat_Panel1, 81);
    lv_obj_clear_flag(ui_Chat_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Chat_Panel1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Chat_Panel1, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chat_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chat_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chat_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chat_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chat_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat1 = ui_Small_Label_create(ui_Chat_Panel1);
    lv_obj_set_width(ui_Chat1, lv_pct(100));
    lv_obj_set_height(ui_Chat1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat1, 0);
    lv_obj_set_y(ui_Chat1, 0);
    lv_obj_set_align(ui_Chat1, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_Chat1, "Let's get some dinner, how about pizza?");
    lv_obj_set_style_text_color(ui_Chat1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chat1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Icon1 = lv_img_create(ui_C1);
    lv_img_set_src(ui_Chat_Icon1, &ui_img_chatbox_png);
    lv_obj_set_width(ui_Chat_Icon1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Chat_Icon1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat_Icon1, 0);
    lv_obj_set_y(ui_Chat_Icon1, 80);
    lv_obj_add_flag(ui_Chat_Icon1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Chat_Icon1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Chat_Icon1, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Chat_Icon1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_C2 = lv_obj_create(ui_Chat_container);
    lv_obj_set_height(ui_C2, 100);
    lv_obj_set_width(ui_C2, lv_pct(100));
    lv_obj_set_x(ui_C2, 0);
    lv_obj_set_y(ui_C2, 160);
    lv_obj_clear_flag(ui_C2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_C2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_C2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_C2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_C2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_C2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_C2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Panel2 = lv_obj_create(ui_C2);
    lv_obj_set_width(ui_Chat_Panel2, 169);
    lv_obj_set_height(ui_Chat_Panel2, 81);
    lv_obj_set_align(ui_Chat_Panel2, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Chat_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Chat_Panel2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Chat_Panel2, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chat_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chat_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chat_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chat_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chat_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat2 = ui_Small_Label_create(ui_Chat_Panel2);
    lv_obj_set_width(ui_Chat2, lv_pct(100));
    lv_obj_set_height(ui_Chat2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat2, 0);
    lv_obj_set_y(ui_Chat2, 0);
    lv_obj_set_align(ui_Chat2, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_Chat2, "Sounds good! What about James?");
    lv_obj_set_style_text_color(ui_Chat2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chat2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Icon2 = lv_img_create(ui_C2);
    lv_img_set_src(ui_Chat_Icon2, &ui_img_chatbox2_png);
    lv_obj_set_width(ui_Chat_Icon2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Chat_Icon2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat_Icon2, 0);
    lv_obj_set_y(ui_Chat_Icon2, 80);
    lv_obj_set_align(ui_Chat_Icon2, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Chat_Icon2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Chat_Icon2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Chat_Icon2, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Chat_Icon2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Delifered = ui_Small_Label_create(ui_C2);
    lv_obj_set_x(ui_Delifered, 47);
    lv_obj_set_y(ui_Delifered, 83);
    lv_obj_set_align(ui_Delifered, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_Delifered, "Delivered");
    lv_obj_set_style_text_color(ui_Delifered, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Delifered, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_C3 = lv_obj_create(ui_Chat_container);
    lv_obj_set_height(ui_C3, 100);
    lv_obj_set_width(ui_C3, lv_pct(100));
    lv_obj_set_x(ui_C3, 0);
    lv_obj_set_y(ui_C3, 270);
    lv_obj_clear_flag(ui_C3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_C3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_C3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_C3, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_C3, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_C3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_C3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Panel3 = lv_obj_create(ui_C3);
    lv_obj_set_width(ui_Chat_Panel3, 169);
    lv_obj_set_height(ui_Chat_Panel3, 81);
    lv_obj_clear_flag(ui_Chat_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Chat_Panel3, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Chat_Panel3, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chat_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chat_Panel3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chat_Panel3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chat_Panel3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chat_Panel3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat3 = ui_Small_Label_create(ui_Chat_Panel3);
    lv_obj_set_width(ui_Chat3, lv_pct(100));
    lv_obj_set_height(ui_Chat3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat3, 0);
    lv_obj_set_y(ui_Chat3, 0);
    lv_obj_set_align(ui_Chat3, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_Chat3, "He likes it too! Where do we meet?");
    lv_obj_set_style_text_color(ui_Chat3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chat3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chat_Icon3 = lv_img_create(ui_C3);
    lv_img_set_src(ui_Chat_Icon3, &ui_img_chatbox_png);
    lv_obj_set_width(ui_Chat_Icon3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Chat_Icon3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chat_Icon3, 0);
    lv_obj_set_y(ui_Chat_Icon3, 80);
    lv_obj_add_flag(ui_Chat_Icon3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Chat_Icon3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Chat_Icon3, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Chat_Icon3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Scrolldots2 = ui_Scrolldots_create(ui_Chat);
    lv_obj_set_x(ui_Scrolldots2, 0);
    lv_obj_set_y(ui_Scrolldots2, -8);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D1), 4);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D1), 4);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D2), 10);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D2), 0);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), 8);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), 8);
    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), 21);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots2, UI_COMP_SCROLLDOTS_D3), 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Chat, ui_event_Chat, LV_EVENT_ALL, NULL);
}

void ui_Weather_screen_init(void) {
    ui_Weather = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Weather, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Weather, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Weather, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Weather, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Pary_Cloud = ui_Small_Label_create(ui_Weather);
    lv_obj_set_x(ui_Pary_Cloud, 0);
    lv_obj_set_y(ui_Pary_Cloud, 5);
    lv_obj_set_align(ui_Pary_Cloud, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Pary_Cloud, "Party cloud");
    lv_obj_set_style_text_color(ui_Pary_Cloud, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Pary_Cloud, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_New_York = ui_Small_Label_create(ui_Weather);
    lv_obj_set_x(ui_New_York, -2);
    lv_obj_set_y(ui_New_York, -84);
    lv_obj_set_align(ui_New_York, LV_ALIGN_CENTER);
    lv_label_set_text(ui_New_York, "New York");
    lv_obj_set_style_text_color(ui_New_York, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_New_York, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Cloud = lv_img_create(ui_Weather);
    lv_img_set_src(ui_Cloud, &ui_img_cloud_png);
    lv_obj_set_width(ui_Cloud, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Cloud, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Cloud, -35);
    lv_obj_set_y(ui_Cloud, 51);
    lv_obj_set_align(ui_Cloud, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Cloud, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Cloud, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Cloud, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Cloud, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Celsius = lv_label_create(ui_Weather);
    lv_obj_set_width(ui_Celsius, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Celsius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Celsius, 39);
    lv_obj_set_y(ui_Celsius, 56);
    lv_obj_set_align(ui_Celsius, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Celsius, "26°");
    lv_obj_set_style_text_color(ui_Celsius, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Celsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Celsius, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Weather_Icons = lv_obj_create(ui_Weather);
    lv_obj_set_height(ui_Weather_Icons, 48);
    lv_obj_set_width(ui_Weather_Icons, lv_pct(90));
    lv_obj_set_x(ui_Weather_Icons, 1);
    lv_obj_set_y(ui_Weather_Icons, -44);
    lv_obj_set_align(ui_Weather_Icons, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_Weather_Icons, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Weather_Icons, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather_Icons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w1 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w1, &ui_img_weather_1_png);
    lv_obj_set_width(ui_w1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_w1, 40);
    lv_obj_set_y(ui_w1, 0);
    lv_obj_add_flag(ui_w1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w1, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w2 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w2, &ui_img_weather_2_png);
    lv_obj_set_width(ui_w2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_w2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_w2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w2, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w3 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w3, &ui_img_weather_3_png);
    lv_obj_set_width(ui_w3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_w3, -40);
    lv_obj_set_y(ui_w3, 0);
    lv_obj_set_align(ui_w3, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_w3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w3, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_W1_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W1_Num, 35);
    lv_obj_set_y(ui_W1_Num, 25);
    lv_obj_set_align(ui_W1_Num, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_W1_Num, "65°");

    ui_W2_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W2_Num, 0);
    lv_obj_set_y(ui_W2_Num, 25);
    lv_obj_set_align(ui_W2_Num, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_W2_Num, "24km/h");

    ui_W3_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W3_Num, -30);
    lv_obj_set_y(ui_W3_Num, 25);
    lv_obj_set_align(ui_W3_Num, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_W3_Num, "18%");

    ui_Scrolldots4 = ui_Scrolldots_create(ui_Weather);
    lv_obj_set_x(ui_Scrolldots4, 0);
    lv_obj_set_y(ui_Scrolldots4, -8);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D1), 4);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D1), 4);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D2), 10);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D2), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D3), 20);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D3), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D4), 30);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D4), 0);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 8);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 8);
    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 41);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Weather, ui_event_Weather, LV_EVENT_ALL, NULL);
}

void ui_Alarm_screen_init(void) {
    ui_Alarm = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Alarm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Alarm, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Alarm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Alarm, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Alarm, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Alarm_container = lv_obj_create(ui_Alarm);
    lv_obj_set_width(ui_Alarm_container, lv_pct(100));
    lv_obj_set_height(ui_Alarm_container, lv_pct(100));
    lv_obj_set_align(ui_Alarm_container, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Alarm_container, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Alarm_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Set_alarm = ui_Small_Label_create(ui_Alarm_container);
    lv_obj_set_x(ui_Set_alarm, 0);
    lv_obj_set_y(ui_Set_alarm, 17);
    lv_obj_set_align(ui_Set_alarm, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Set_alarm, "Set alarm");
    lv_obj_set_style_text_color(ui_Set_alarm, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Set_alarm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Alarm_Comp = ui_Alarm_Comp_create(ui_Alarm_container);
    lv_obj_set_x(ui_Alarm_Comp, 0);
    lv_obj_set_y(ui_Alarm_Comp, 43);

    ui_Alarm_Comp1 = ui_Alarm_Comp_create(ui_Alarm_container);
    lv_obj_set_x(ui_Alarm_Comp1, 0);
    lv_obj_set_y(ui_Alarm_Comp1, 128);

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp1, UI_COMP_ALARM_COMP_ALARM_NUM2), "8:00");

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp1, UI_COMP_ALARM_COMP_PERIOD), "Breakfast");

    lv_obj_add_state(ui_comp_get_child(ui_Alarm_Comp1, UI_COMP_ALARM_COMP_SWITCH1), LV_STATE_CHECKED);       /// States

    ui_Alarm_Comp2 = ui_Alarm_Comp_create(ui_Alarm_container);
    lv_obj_set_x(ui_Alarm_Comp2, 0);
    lv_obj_set_y(ui_Alarm_Comp2, 213);

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp2, UI_COMP_ALARM_COMP_ALARM_NUM2), "9:30");

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp2, UI_COMP_ALARM_COMP_PERIOD), "Yoga");

    ui_Alarm_Comp3 = ui_Alarm_Comp_create(ui_Alarm_container);
    lv_obj_set_x(ui_Alarm_Comp3, 0);
    lv_obj_set_y(ui_Alarm_Comp3, 298);
    lv_obj_set_style_border_color(ui_Alarm_Comp3, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Alarm_Comp3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Alarm_Comp3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Alarm_Comp3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp3, UI_COMP_ALARM_COMP_ALARM_NUM2), "11:00");

    lv_label_set_text(ui_comp_get_child(ui_Alarm_Comp3, UI_COMP_ALARM_COMP_PERIOD), "Sleep");

    ui_Scrolldots5 = ui_Scrolldots_create(ui_Alarm);
    lv_obj_set_x(ui_Scrolldots5, 0);
    lv_obj_set_y(ui_Scrolldots5, -8);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D1), 4);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D1), 4);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D2), 10);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D2), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D3), 20);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D3), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D4), 30);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D4), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D5), 40);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D5), 0);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), 8);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), 8);
    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), 50);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots5, UI_COMP_SCROLLDOTS_D6), 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Alarm, ui_event_Alarm, LV_EVENT_ALL, NULL);
}

void ui_init(void) {
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    ui_Clock_screen_init();
    ui_Chat_screen_init();
    ui_Weather_screen_init();
    ui_Alarm_screen_init();
    lv_disp_load_scr(ui_Clock);
}
