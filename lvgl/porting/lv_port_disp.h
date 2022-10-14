#ifndef LV_PORT_DISP_TEMPL_H
#define LV_PORT_DISP_TEMPL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_port_disp_init(void);
void disp_enable_update(void);
void disp_disable_update(void);

void disp_blk_set(void);
void disp_blk_reset(void);

#ifdef __cplusplus
}
#endif

#endif
