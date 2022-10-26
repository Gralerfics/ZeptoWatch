// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: ZeptoWatchUI

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Home;
lv_obj_t * ui_Test_Spinner;
lv_obj_t * ui_Home_Arc2;
lv_obj_t * ui_Home_Roller2;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Test_Spinner = lv_spinner_create(ui_Home, 1000, 90);
    lv_obj_set_width(ui_Test_Spinner, 150);
    lv_obj_set_height(ui_Test_Spinner, 150);
    lv_obj_set_align(ui_Test_Spinner, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Test_Spinner, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_Home_Arc2 = lv_arc_create(ui_Home);
    lv_obj_set_width(ui_Home_Arc2, 200);
    lv_obj_set_height(ui_Home_Arc2, 200);
    lv_obj_set_align(ui_Home_Arc2, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_Home_Arc2, 60);

    ui_Home_Roller2 = lv_roller_create(ui_Home);
    lv_roller_set_options(ui_Home_Roller2, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Home_Roller2, 78);
    lv_obj_set_width(ui_Home_Roller2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_Home_Roller2, LV_ALIGN_CENTER);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Home_screen_init();
    lv_disp_load_scr(ui_Home);
}
