#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/* ==================== Body ==================== */
void delay_us(uint32_t t);
void delay_ms(uint32_t t);

#ifdef __cplusplus
}
#endif

#endif
