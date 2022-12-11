// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: est

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Label1;
lv_obj_t * ui_Screen1_Roller1;
void ui_event_Screen1_Button1(lv_event_t * e);
lv_obj_t * ui_Screen1_Button1;
lv_obj_t * ui_Screen2;
void ui_event_Screen2_Button2(lv_event_t * e);
lv_obj_t * ui_Screen2_Button2;
lv_obj_t * ui_Screen2_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Screen1_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
		btn1Clicked(e);
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Screen2_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
		btn2Clicked(e);
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label1, 145);
    lv_obj_set_height(ui_Screen1_Label1, 50);
    lv_obj_set_x(ui_Screen1_Label1, 0);
    lv_obj_set_y(ui_Screen1_Label1, 70);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Screen1_Label1, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Roller1 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Screen1_Roller1, "Scanning ...", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_Screen1_Roller1, 145);
    lv_obj_set_height(ui_Screen1_Roller1, 66);
    lv_obj_set_x(ui_Screen1_Roller1, 0);
    lv_obj_set_y(ui_Screen1_Roller1, -40);
    lv_obj_set_align(ui_Screen1_Roller1, LV_ALIGN_CENTER);

    ui_Screen1_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button1, 100);
    lv_obj_set_height(ui_Screen1_Button1, 29);
    lv_obj_set_x(ui_Screen1_Button1, 0);
    lv_obj_set_y(ui_Screen1_Button1, 20);
    lv_obj_set_align(ui_Screen1_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Screen1_Button1, ui_event_Screen1_Button1, LV_EVENT_ALL, NULL);

}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen2_Button2 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_Button2, 32);
    lv_obj_set_height(ui_Screen2_Button2, 31);
    lv_obj_set_x(ui_Screen2_Button2, 0);
    lv_obj_set_y(ui_Screen2_Button2, 96);
    lv_obj_set_align(ui_Screen2_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen2_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen2_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen2_Label1 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_Label1, 145);
    lv_obj_set_height(ui_Screen2_Label1, 145);
    lv_obj_set_align(ui_Screen2_Label1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Screen2_Label1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen2_Button2, ui_event_Screen2_Button2, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
