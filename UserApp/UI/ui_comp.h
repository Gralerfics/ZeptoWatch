// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: Smart_Gadget

#ifndef _SMART_GADGET_UI_COMP_H
#define _SMART_GADGET_UI_COMP_H

#include "ui.h"

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx);
extern uint32_t LV_EVENT_GET_COMP_CHILD;

// COMPONENT Alarm Comp
#define UI_COMP_ALARM_COMP_ALARM_COMP 0
#define UI_COMP_ALARM_COMP_ALARM_NUM2 1
#define UI_COMP_ALARM_COMP_PERIOD 2
#define UI_COMP_ALARM_COMP_SWITCH1 3
#define _UI_COMP_ALARM_COMP_NUM 4
lv_obj_t * ui_Alarm_Comp_create(lv_obj_t * comp_parent);

// COMPONENT Clock Dot
#define UI_COMP_CLOCK_DOT_CLOCK_DOT 0
#define _UI_COMP_CLOCK_DOT_NUM 1
lv_obj_t * ui_Clock_Dot_create(lv_obj_t * comp_parent);

// COMPONENT Scrolldots
#define UI_COMP_SCROLLDOTS_SCROLLDOTS 0
#define UI_COMP_SCROLLDOTS_D1 1
#define UI_COMP_SCROLLDOTS_D2 2
#define UI_COMP_SCROLLDOTS_D3 3
#define UI_COMP_SCROLLDOTS_D4 4
#define UI_COMP_SCROLLDOTS_D5 5
#define UI_COMP_SCROLLDOTS_D6 6
#define _UI_COMP_SCROLLDOTS_NUM 7
lv_obj_t * ui_Scrolldots_create(lv_obj_t * comp_parent);

// COMPONENT Small Label
#define UI_COMP_SMALL_LABEL_SMALL_LABEL 0
#define _UI_COMP_SMALL_LABEL_NUM 1
lv_obj_t * ui_Small_Label_create(lv_obj_t * comp_parent);

#endif
