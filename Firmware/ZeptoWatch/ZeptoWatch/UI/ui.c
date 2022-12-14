// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: systemui

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void dropdownDropping_Animation(lv_obj_t * TargetObject, int delay);
void dropdownLeaving_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Home(lv_event_t * e);
lv_obj_t * ui_Home;
lv_obj_t * ui_secPtr;
lv_obj_t * ui_minPtr;
lv_obj_t * ui_hourPtr;
lv_obj_t * ui_ptrDot;
lv_obj_t * ui_clockDot12;
lv_obj_t * ui_clockDot6;
lv_obj_t * ui_clockDot3;
lv_obj_t * ui_clockDot9;
lv_obj_t * ui_Dropdown;
lv_obj_t * ui_dropdownPanel;
lv_obj_t * ui_dropdownTimeLabel;
lv_obj_t * ui_dropdownBatterySlider;
lv_obj_t * ui_dropdownBrightnessSlider;
void ui_event_dropdownBtn(lv_event_t * e);
lv_obj_t * ui_dropdownBtn;
lv_obj_t * ui_Applications;
lv_obj_t * ui_Applications_Label1;
lv_obj_t * ui_Appfield;
lv_obj_t * ui_Shutdown;
lv_obj_t * ui_shutdownLabel;
lv_obj_t * ui_shutdownConfirmBtn;
lv_obj_t * ui_shutdownBackBtn;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void dropdownDropping_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -240, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void dropdownLeaving_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -240);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Home(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        dropdownDropping_Animation(ui_dropdownPanel, 0);
        _ui_screen_change(ui_Dropdown, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
    }
}
void ui_event_dropdownBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 150);
        dropdownLeaving_Animation(ui_dropdownPanel, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_secPtr = lv_img_create(ui_Home);
    lv_img_set_src(ui_secPtr, &ui_img_clock_sec_png);
    lv_obj_set_width(ui_secPtr, LV_SIZE_CONTENT);   /// 3
    lv_obj_set_height(ui_secPtr, LV_SIZE_CONTENT);    /// 144
    lv_obj_set_align(ui_secPtr, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_secPtr, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_secPtr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_minPtr = lv_img_create(ui_Home);
    lv_img_set_src(ui_minPtr, &ui_img_clock_min_png);
    lv_obj_set_width(ui_minPtr, LV_SIZE_CONTENT);   /// 8
    lv_obj_set_height(ui_minPtr, LV_SIZE_CONTENT);    /// 110
    lv_obj_set_align(ui_minPtr, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_minPtr, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_minPtr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_hourPtr = lv_img_create(ui_Home);
    lv_img_set_src(ui_hourPtr, &ui_img_clock_hour_png);
    lv_obj_set_width(ui_hourPtr, LV_SIZE_CONTENT);   /// 8
    lv_obj_set_height(ui_hourPtr, LV_SIZE_CONTENT);    /// 88
    lv_obj_set_align(ui_hourPtr, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_hourPtr, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_hourPtr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ptrDot = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_ptrDot, 8);
    lv_obj_set_height(ui_ptrDot, 8);
    lv_obj_set_align(ui_ptrDot, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ptrDot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ptrDot, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ptrDot, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ptrDot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ptrDot, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockDot12 = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_clockDot12, 3);
    lv_obj_set_height(ui_clockDot12, 3);
    lv_obj_set_x(ui_clockDot12, 0);
    lv_obj_set_y(ui_clockDot12, 25);
    lv_obj_set_align(ui_clockDot12, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_clockDot12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_clockDot12, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_clockDot12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clockDot12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_clockDot12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockDot6 = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_clockDot6, 3);
    lv_obj_set_height(ui_clockDot6, 3);
    lv_obj_set_x(ui_clockDot6, 0);
    lv_obj_set_y(ui_clockDot6, -25);
    lv_obj_set_align(ui_clockDot6, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_clockDot6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_clockDot6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_clockDot6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clockDot6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_clockDot6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockDot3 = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_clockDot3, 3);
    lv_obj_set_height(ui_clockDot3, 3);
    lv_obj_set_x(ui_clockDot3, -25);
    lv_obj_set_y(ui_clockDot3, 0);
    lv_obj_set_align(ui_clockDot3, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_clockDot3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_clockDot3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_clockDot3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clockDot3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_clockDot3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockDot9 = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_clockDot9, 3);
    lv_obj_set_height(ui_clockDot9, 3);
    lv_obj_set_x(ui_clockDot9, 25);
    lv_obj_set_y(ui_clockDot9, 0);
    lv_obj_set_align(ui_clockDot9, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_clockDot9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_clockDot9, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_clockDot9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clockDot9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_clockDot9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

}
void ui_Dropdown_screen_init(void)
{
    ui_Dropdown = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Dropdown, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_dropdownPanel = lv_obj_create(ui_Dropdown);
    lv_obj_set_width(ui_dropdownPanel, 240);
    lv_obj_set_height(ui_dropdownPanel, 240);
    lv_obj_set_x(ui_dropdownPanel, 0);
    lv_obj_set_y(ui_dropdownPanel, -1);
    lv_obj_set_align(ui_dropdownPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dropdownPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_dropdownPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dropdownPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_dropdownPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dropdownTimeLabel = lv_label_create(ui_dropdownPanel);
    lv_obj_set_width(ui_dropdownTimeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dropdownTimeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dropdownTimeLabel, 0);
    lv_obj_set_y(ui_dropdownTimeLabel, 26);
    lv_obj_set_align(ui_dropdownTimeLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dropdownTimeLabel, "00 : 00 : 00");

    ui_dropdownBatterySlider = lv_slider_create(ui_dropdownPanel);
    lv_slider_set_value(ui_dropdownBatterySlider, 75, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_dropdownBatterySlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(
            ui_dropdownBatterySlider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_dropdownBatterySlider, 60);
    lv_obj_set_height(ui_dropdownBatterySlider, 61);
    lv_obj_set_x(ui_dropdownBatterySlider, -35);
    lv_obj_set_y(ui_dropdownBatterySlider, -21);
    lv_obj_set_align(ui_dropdownBatterySlider, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dropdownBatterySlider, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_dropdownBatterySlider, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dropdownBatterySlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBatterySlider, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_dropdownBatterySlider, &ui_img_battery_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_dropdownBatterySlider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_dropdownBatterySlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_dropdownBatterySlider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_dropdownBatterySlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_dropdownBatterySlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_dropdownBatterySlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_dropdownBatterySlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_dropdownBatterySlider, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dropdownBatterySlider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBatterySlider, 220, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_dropdownBatterySlider, &ui_img_battery_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_dropdownBatterySlider, lv_color_hex(0x101418), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_dropdownBatterySlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_dropdownBatterySlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBatterySlider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_dropdownBrightnessSlider = lv_slider_create(ui_dropdownPanel);
    lv_slider_set_value(ui_dropdownBrightnessSlider, 60, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_dropdownBrightnessSlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(
            ui_dropdownBrightnessSlider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_dropdownBrightnessSlider, 60);
    lv_obj_set_height(ui_dropdownBrightnessSlider, 128);
    lv_obj_set_x(ui_dropdownBrightnessSlider, 35);
    lv_obj_set_y(ui_dropdownBrightnessSlider, 13);
    lv_obj_set_align(ui_dropdownBrightnessSlider, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_dropdownBrightnessSlider, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dropdownBrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBrightnessSlider, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_dropdownBrightnessSlider, &ui_img_brightness_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_dropdownBrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_dropdownBrightnessSlider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_dropdownBrightnessSlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_dropdownBrightnessSlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_dropdownBrightnessSlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_dropdownBrightnessSlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_dropdownBrightnessSlider, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dropdownBrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBrightnessSlider, 220, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_dropdownBrightnessSlider, &ui_img_brightness_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_dropdownBrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBrightnessSlider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_dropdownBtn = lv_btn_create(ui_dropdownPanel);
    lv_obj_set_width(ui_dropdownBtn, 60);
    lv_obj_set_height(ui_dropdownBtn, 61);
    lv_obj_set_x(ui_dropdownBtn, -35);
    lv_obj_set_y(ui_dropdownBtn, 47);
    lv_obj_set_align(ui_dropdownBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_dropdownBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_dropdownBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_dropdownBtn, lv_color_hex(0xB3B3B3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dropdownBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_dropdownBtn, lv_color_hex(0x293031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_dropdownBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_dropdownBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_dropdownBtn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_dropdownBtn, ui_event_dropdownBtn, LV_EVENT_ALL, NULL);

}
void ui_Applications_screen_init(void)
{
    ui_Applications = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Applications, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Applications, 120, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Applications_Label1 = lv_label_create(ui_Applications);
    lv_obj_set_width(ui_Applications_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Applications_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Applications_Label1, 0);
    lv_obj_set_y(ui_Applications_Label1, -75);
    lv_obj_set_align(ui_Applications_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Applications_Label1, "Applications");

}
void ui_Appfield_screen_init(void)
{
    ui_Appfield = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Appfield, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Appfield, 120, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_Shutdown_screen_init(void)
{
    ui_Shutdown = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Shutdown, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_shutdownLabel = lv_label_create(ui_Shutdown);
    lv_obj_set_width(ui_shutdownLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_shutdownLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_shutdownLabel, 0);
    lv_obj_set_y(ui_shutdownLabel, -60);
    lv_obj_set_align(ui_shutdownLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_shutdownLabel, "Confirm?");

    ui_shutdownConfirmBtn = lv_btn_create(ui_Shutdown);
    lv_obj_set_width(ui_shutdownConfirmBtn, 90);
    lv_obj_set_height(ui_shutdownConfirmBtn, 90);
    lv_obj_set_x(ui_shutdownConfirmBtn, -19);
    lv_obj_set_y(ui_shutdownConfirmBtn, 5);
    lv_obj_set_align(ui_shutdownConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_shutdownConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_shutdownConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_shutdownConfirmBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_shutdownConfirmBtn, lv_color_hex(0xFF4545), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shutdownConfirmBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_shutdownConfirmBtn, &ui_img_power_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_shutdownConfirmBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_shutdownConfirmBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shutdownBackBtn = lv_btn_create(ui_Shutdown);
    lv_obj_set_width(ui_shutdownBackBtn, 50);
    lv_obj_set_height(ui_shutdownBackBtn, 50);
    lv_obj_set_x(ui_shutdownBackBtn, 36);
    lv_obj_set_y(ui_shutdownBackBtn, 41);
    lv_obj_set_align(ui_shutdownBackBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_shutdownBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_shutdownBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_shutdownBackBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_shutdownBackBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shutdownBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Home_screen_init();
    ui_Dropdown_screen_init();
    ui_Applications_screen_init();
    ui_Appfield_screen_init();
    ui_Shutdown_screen_init();
    lv_disp_load_scr(ui_Home);
}
