#ifndef __BT11_H
#define __BT11_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/*
 * BT_RST -> PA1
 * BT -> USART2_TX -> PA2
 * 		 USART2_RX -> PA3
 */

#define __HAL_RCC_BT_RST_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define BT_RST_Pin GPIO_PIN_1
#define BT_RST_GPIO_Port GPIOA

extern uint8_t rx_buffer[100];
extern volatile uint8_t rx_len;
extern volatile uint8_t recv_end_flag;

void BT11_Init();
void BT11_Reset();

#ifdef __cplusplus
}
#endif

#endif
