#ifndef __UI_USER_H
#define __UI_USER_H

#include "ui_helpers.h"

/* TODO: 更新 Squareline 记得把本头文件加到 ui.c, ui_helpers.c 里, 并修改如下函数 */
//	void _ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay)
//	{
//		lv_scr_load_anim(target, fademode, spd, delay, false);
//		if (target != ui_Shutdown) {
//			setUICurrentPage(target);
//		}
//	}

void setUICurrentPage(lv_obj_t *v);
lv_obj_t* getUICurrentPage();

void ui_event_appButtons(lv_event_t *e);

void shutdownConfirmed(lv_event_t *e);
void shutdownBack(lv_event_t *e);
void quitFromApplication(lv_event_t *e);
void callShutdown();
void callApplication(lv_event_t *e);
void refreshAppList(lv_event_t *e);

void UI_Clock_Arrows_Reset();
void UI_Clock_InitArrows();

LV_IMG_DECLARE(ui_img_scripts_png);    	// assets\scripts.png
LV_IMG_DECLARE(ui_img_timer_png);    	// assets\timer.png
LV_IMG_DECLARE(ui_img_calc_png);    	// assets\calc.png
LV_IMG_DECLARE(ui_img_canlendar_png);  	// assets\canlendar.png
LV_IMG_DECLARE(ui_img_settings_png);   	// assets\settings.png
LV_IMG_DECLARE(ui_img_info_png);    	// assets\info.png
LV_IMG_DECLARE(ui_img_clock_png);    	// assets\clock.png
LV_IMG_DECLARE(ui_img_check_png);    	// assets\check.png
LV_IMG_DECLARE(ui_img_notes_png);    	// assets\notes.png

#endif
