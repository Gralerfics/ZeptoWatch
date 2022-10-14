// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: Smart_Gadget


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT Alarm Comp

lv_obj_t * ui_Alarm_Comp_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Alarm_Comp;
    cui_Alarm_Comp = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Alarm_Comp, 80);
    lv_obj_set_width(cui_Alarm_Comp, lv_pct(94));
    lv_obj_set_x(cui_Alarm_Comp, 0);
    lv_obj_set_y(cui_Alarm_Comp, 43);
    lv_obj_set_align(cui_Alarm_Comp, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Alarm_Comp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Alarm_Comp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Alarm_Comp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_Alarm_Comp, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Alarm_Comp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_Alarm_Comp, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_Alarm_Comp, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Alarm_Comp, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Alarm_Comp, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Alarm_Comp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Alarm_Comp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Alarm_Num2;
    cui_Alarm_Num2 = lv_label_create(cui_Alarm_Comp);
    lv_obj_set_width(cui_Alarm_Num2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Alarm_Num2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Alarm_Num2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Alarm_Num2, "7:00");
    lv_obj_set_style_text_color(cui_Alarm_Num2, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Alarm_Num2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Alarm_Num2, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ui_Period;
    ui_Period = ui_Small_Label_create(cui_Alarm_Comp);
    lv_obj_set_x(ui_Period, -5);
    lv_obj_set_y(ui_Period, -6);
    lv_obj_set_align(ui_Period, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_Period, "Wake Up!");

    lv_obj_t * cui_Switch1;
    cui_Switch1 = lv_switch_create(cui_Alarm_Comp);
    lv_obj_set_width(cui_Switch1, 61);
    lv_obj_set_height(cui_Switch1, 32);
    lv_obj_set_x(cui_Switch1, -4);
    lv_obj_set_y(cui_Switch1, 11);
    lv_obj_set_align(cui_Switch1, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_radius(cui_Switch1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch1, lv_color_hex(0x9D9ED5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Switch1, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch1, lv_color_hex(0x293062), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_Switch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(cui_Switch1, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Switch1, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Switch1, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Switch1, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Switch1, -3, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_ALARM_COMP_NUM);
    children[UI_COMP_ALARM_COMP_ALARM_COMP] = cui_Alarm_Comp;
    children[UI_COMP_ALARM_COMP_ALARM_NUM2] = cui_Alarm_Num2;
    children[UI_COMP_ALARM_COMP_PERIOD] = ui_Period;
    children[UI_COMP_ALARM_COMP_SWITCH1] = cui_Switch1;
    lv_obj_add_event_cb(cui_Alarm_Comp, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Alarm_Comp, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Alarm_Comp;
}



// COMPONENT Clock Dot

lv_obj_t * ui_Clock_Dot_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Clock_Dot;
    cui_Clock_Dot = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Clock_Dot, 6);
    lv_obj_set_height(cui_Clock_Dot, 6);
    lv_obj_set_x(cui_Clock_Dot, -10);
    lv_obj_set_y(cui_Clock_Dot, 50);
    lv_obj_set_align(cui_Clock_Dot, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(cui_Clock_Dot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Clock_Dot, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Clock_Dot, lv_color_hex(0xB3B4E5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Clock_Dot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_CLOCK_DOT_NUM);
    children[UI_COMP_CLOCK_DOT_CLOCK_DOT] = cui_Clock_Dot;
    lv_obj_add_event_cb(cui_Clock_Dot, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Clock_Dot, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Clock_Dot;
}



// COMPONENT Scrolldots

lv_obj_t * ui_Scrolldots_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Scrolldots;
    cui_Scrolldots = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Scrolldots, 65);
    lv_obj_set_height(cui_Scrolldots, 12);
    lv_obj_set_x(cui_Scrolldots, 0);
    lv_obj_set_y(cui_Scrolldots, -8);
    lv_obj_set_align(cui_Scrolldots, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Scrolldots, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Scrolldots, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Scrolldots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d1;
    cui_d1 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d1, 8);
    lv_obj_set_height(cui_d1, 8);
    lv_obj_set_align(cui_d1, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d1, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d2;
    cui_d2 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d2, 4);
    lv_obj_set_height(cui_d2, 4);
    lv_obj_set_x(cui_d2, 15);
    lv_obj_set_y(cui_d2, 0);
    lv_obj_set_align(cui_d2, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d2, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d3;
    cui_d3 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d3, 4);
    lv_obj_set_height(cui_d3, 4);
    lv_obj_set_x(cui_d3, 25);
    lv_obj_set_y(cui_d3, 0);
    lv_obj_set_align(cui_d3, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d3, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d4;
    cui_d4 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d4, 4);
    lv_obj_set_height(cui_d4, 4);
    lv_obj_set_x(cui_d4, 35);
    lv_obj_set_y(cui_d4, 0);
    lv_obj_set_align(cui_d4, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d4, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d5;
    cui_d5 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d5, 4);
    lv_obj_set_height(cui_d5, 4);
    lv_obj_set_x(cui_d5, 45);
    lv_obj_set_y(cui_d5, 0);
    lv_obj_set_align(cui_d5, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d5, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d5, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_d6;
    cui_d6 = lv_obj_create(cui_Scrolldots);
    lv_obj_set_width(cui_d6, 4);
    lv_obj_set_height(cui_d6, 4);
    lv_obj_set_x(cui_d6, 55);
    lv_obj_set_y(cui_d6, 0);
    lv_obj_set_align(cui_d6, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_d6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_d6, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_d6, lv_color_hex(0xB4B6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_d6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SCROLLDOTS_NUM);
    children[UI_COMP_SCROLLDOTS_SCROLLDOTS] = cui_Scrolldots;
    children[UI_COMP_SCROLLDOTS_D1] = cui_d1;
    children[UI_COMP_SCROLLDOTS_D2] = cui_d2;
    children[UI_COMP_SCROLLDOTS_D3] = cui_d3;
    children[UI_COMP_SCROLLDOTS_D4] = cui_d4;
    children[UI_COMP_SCROLLDOTS_D5] = cui_d5;
    children[UI_COMP_SCROLLDOTS_D6] = cui_d6;
    lv_obj_add_event_cb(cui_Scrolldots, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Scrolldots, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Scrolldots;
}



// COMPONENT Small Label

lv_obj_t * ui_Small_Label_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Small_Label;
    cui_Small_Label = lv_label_create(comp_parent);
    lv_obj_set_width(cui_Small_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Small_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Small_Label, 0);
    lv_obj_set_y(cui_Small_Label, 72);
    lv_obj_set_align(cui_Small_Label, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Small_Label, "12");
    lv_obj_set_style_text_color(cui_Small_Label, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Small_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Small_Label, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SMALL_LABEL_NUM);
    children[UI_COMP_SMALL_LABEL_SMALL_LABEL] = cui_Small_Label;
    lv_obj_add_event_cb(cui_Small_Label, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Small_Label, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Small_Label;
}

