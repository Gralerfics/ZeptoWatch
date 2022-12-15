#ifndef __UI_HELPERS_USER_H
#define __UI_HELPERS_USER_H

#include "ui_helpers.h"

void UI_Applications_InitList();
void UI_Applications_Listing();

void UI_Animate_PtrTicking(lv_obj_t *TargetObject, int start, int end, int time, int delay);
void UI_Animate_PtrIniting(lv_obj_t * TargetObject, int end, int delay);

#endif
