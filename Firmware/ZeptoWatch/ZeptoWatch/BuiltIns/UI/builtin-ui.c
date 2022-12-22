// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: est

#include "builtin-ui.h"
#include "ui_helpers.h"
#include "ui_user.h"
#include "builtin-ui_user.h"

///////////////////// VARIABLES ////////////////////
void beatfish_Animation(lv_obj_t * TargetObject, int delay);
//void beatShowLabel_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_woodenfImg;
lv_obj_t * ui_woodenfIncLabel;
lv_obj_t * ui_woodenfAccLabel;
void ui_event_woodenfBtn(lv_event_t * e);
lv_obj_t * ui_woodenfBtn;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void beatfish_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 50);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 225, 240);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 25);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_1, 240, 225);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 100);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
//void beatShowLabel_Animation(lv_obj_t * TargetObject, int delay)
//{
//    lv_anim_t PropertyAnimation_0;
//    lv_anim_init(&PropertyAnimation_0);
//    lv_anim_set_time(&PropertyAnimation_0, 300);
//    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
//    lv_anim_set_values(&PropertyAnimation_0, -50, -80);
//    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//    lv_anim_set_early_apply(&PropertyAnimation_0, false);
//    lv_anim_start(&PropertyAnimation_0);
//    lv_anim_t PropertyAnimation_1;
//    lv_anim_init(&PropertyAnimation_1);
//    lv_anim_set_time(&PropertyAnimation_1, 300);
//    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
//    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
//    lv_anim_set_values(&PropertyAnimation_1, 255, 0);
//    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
//    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
//    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
//    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
//    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
//    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
//    lv_anim_set_early_apply(&PropertyAnimation_1, false);
//    lv_anim_start(&PropertyAnimation_1);
//
//}

///////////////////// FUNCTIONS ///////////////////
void ui_event_woodenfBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        beatfish_Animation(ui_woodenfImg, 0);
//        beatShowLabel_Animation(ui_woodenfIncLabel, 0);
        woodenfMeritsInc(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Woodenf_screen_init(void)
{
    ui_woodenfImg = lv_img_create(ui_Appfield);
    lv_img_set_src(ui_woodenfImg, &ui_img_woodenf_png);
    lv_obj_set_width(ui_woodenfImg, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_woodenfImg, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_woodenfImg, -6);
    lv_obj_set_y(ui_woodenfImg, -2);
    lv_obj_set_align(ui_woodenfImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_woodenfImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_woodenfImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_woodenfImg, 225);

//    ui_woodenfIncLabel = lv_label_create(ui_Appfield);
//    lv_obj_set_width(ui_woodenfIncLabel, LV_SIZE_CONTENT);   /// 1
//    lv_obj_set_height(ui_woodenfIncLabel, LV_SIZE_CONTENT);    /// 1
//    lv_obj_set_x(ui_woodenfIncLabel, -49);
//    lv_obj_set_y(ui_woodenfIncLabel, -50);
//    lv_obj_set_align(ui_woodenfIncLabel, LV_ALIGN_CENTER);
//    lv_label_set_text(ui_woodenfIncLabel, "Merit + 1");
//    lv_obj_set_style_text_font(ui_woodenfIncLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_opa(ui_woodenfIncLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_woodenfAccLabel = lv_label_create(ui_Appfield);
    lv_obj_set_width(ui_woodenfAccLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_woodenfAccLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_woodenfAccLabel, 0);
    lv_obj_set_y(ui_woodenfAccLabel, 80);
    lv_obj_set_align(ui_woodenfAccLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_woodenfAccLabel, "Knock.");
    lv_obj_set_style_text_font(ui_woodenfAccLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_woodenfBtn = lv_btn_create(ui_Appfield);
    lv_obj_set_width(ui_woodenfBtn, 131);
    lv_obj_set_height(ui_woodenfBtn, 99);
    lv_obj_set_x(ui_woodenfBtn, -5);
    lv_obj_set_y(ui_woodenfBtn, -2);
    lv_obj_set_align(ui_woodenfBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_woodenfBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_woodenfBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_woodenfBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_woodenfBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_woodenfBtn, ui_event_woodenfBtn, LV_EVENT_ALL, NULL);

}
