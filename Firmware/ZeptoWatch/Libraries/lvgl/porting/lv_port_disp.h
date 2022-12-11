#ifndef LV_PORT_DISP_TEMPL_H
#define LV_PORT_DISP_TEMPL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

/**********************
 * MACROS
 **********************/
#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 240
#define BUFFER_ROWS 20
#define SINGLE_BUFFERING
#define DIRECT_SWAP_MODE

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_port_disp_init(void);
void disp_enable_update(void);
void disp_disable_update(void);

#ifdef __cplusplus
}
#endif

#endif
