#ifndef REAL_UART_WITH_DMA_DELAY_H
#define REAL_UART_WITH_DMA_DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void delay_us(uint32_t t);

void delay_ms(uint32_t t);

#ifdef __cplusplus
}
#endif

#endif //REAL_UART_WITH_DMA_DELAY_H
