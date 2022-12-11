// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: est

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Main;
lv_obj_t * ui_info;
lv_obj_t * ui_roller;
void ui_event_exeBtn(lv_event_t * e);
lv_obj_t * ui_exeBtn;
lv_obj_t * ui_chart;
lv_obj_t * ui_Application;
void ui_event_backBtn(lv_event_t * e);
lv_obj_t * ui_backBtn;
lv_obj_t * ui_applabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_exeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        btn1Clicked(e);
        _ui_screen_change(ui_Application, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_backBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        btn2Clicked(e);
        _ui_screen_change(ui_Main, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Main_screen_init(void)
{
    ui_Main = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Main, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_info = lv_label_create(ui_Main);
    lv_obj_set_width(ui_info, 145);
    lv_obj_set_height(ui_info, 50);
    lv_obj_set_x(ui_info, 0);
    lv_obj_set_y(ui_info, 71);
    lv_obj_set_align(ui_info, LV_ALIGN_CENTER);
    lv_label_set_text(ui_info, "");
    lv_obj_set_style_text_font(ui_info, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_roller = lv_roller_create(ui_Main);
    lv_roller_set_options(ui_roller, "Scanning ...", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_roller, 127);
    lv_obj_set_height(ui_roller, 54);
    lv_obj_set_x(ui_roller, -16);
    lv_obj_set_y(ui_roller, -63);
    lv_obj_set_align(ui_roller, LV_ALIGN_CENTER);

    ui_exeBtn = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_exeBtn, 24);
    lv_obj_set_height(ui_exeBtn, 44);
    lv_obj_set_x(ui_exeBtn, 68);
    lv_obj_set_y(ui_exeBtn, -63);
    lv_obj_set_align(ui_exeBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_exeBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_exeBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_chart = lv_chart_create(ui_Main);
    lv_obj_set_width(ui_chart, 183);
    lv_obj_set_height(ui_chart, 63);
    lv_obj_set_x(ui_chart, 0);
    lv_obj_set_y(ui_chart, 3);
    lv_obj_set_align(ui_chart, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_exeBtn, ui_event_exeBtn, LV_EVENT_ALL, NULL);

}
void ui_Application_screen_init(void)
{
    ui_Application = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Application, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_backBtn = lv_btn_create(ui_Application);
    lv_obj_set_width(ui_backBtn, 61);
    lv_obj_set_height(ui_backBtn, 31);
    lv_obj_set_x(ui_backBtn, 0);
    lv_obj_set_y(ui_backBtn, 88);
    lv_obj_set_align(ui_backBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_backBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_backBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_applabel = lv_label_create(ui_Application);
    lv_obj_set_width(ui_applabel, 145);
    lv_obj_set_height(ui_applabel, 130);
    lv_obj_set_x(ui_applabel, 0);
    lv_obj_set_y(ui_applabel, -13);
    lv_obj_set_align(ui_applabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_applabel, "");
    lv_obj_set_style_text_font(ui_applabel, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_backBtn, ui_event_backBtn, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Main_screen_init();
    ui_Application_screen_init();
    lv_disp_load_scr(ui_Main);
}
