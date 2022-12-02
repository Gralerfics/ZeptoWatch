// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: est

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Keyboard1;
lv_obj_t * ui_Screen1_TextArea1;
lv_obj_t * ui_Screen1_Label1;

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
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Keyboard1 = lv_keyboard_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Keyboard1, 158);
    lv_obj_set_height(ui_Screen1_Keyboard1, 74);
    lv_obj_set_x(ui_Screen1_Keyboard1, 0);
    lv_obj_set_y(ui_Screen1_Keyboard1, 40);
    lv_obj_set_align(ui_Screen1_Keyboard1, LV_ALIGN_CENTER);

    lv_obj_set_style_text_font(ui_Screen1_Keyboard1, &lv_font_montserrat_8, LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_Screen1_TextArea1 = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_TextArea1, 157);
    lv_obj_set_height(ui_Screen1_TextArea1, 79);
    lv_obj_set_x(ui_Screen1_TextArea1, 0);
    lv_obj_set_y(ui_Screen1_TextArea1, -43);
    lv_obj_set_align(ui_Screen1_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_Screen1_TextArea1, "Placeholder...");

    lv_obj_set_style_text_font(ui_Screen1_TextArea1, &lv_font_montserrat_8,
                               LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Screen1_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label1, -1);
    lv_obj_set_y(ui_Screen1_Label1, -96);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_CENTER);

    lv_keyboard_set_textarea(ui_Screen1_Keyboard1, ui_Screen1_TextArea1);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
