#ifndef _GC9A01_H
#define _GC9A01_H

#include "stm32f4xx_hal.h"
#include "spi.h"

/*
 * LCD_RST -> PC4
 * LCD_DC  -> PC5
 * LCD_SPI -> SPI1: SCL -> PA5
 *                  SDA -> PA7
 *                  CS  -> GND
 */

#define __HAL_RCC_LCD_RST_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define LCD_RST_PORT GPIOC
#define LCD_RST_PIN GPIO_PIN_4

#define __HAL_RCC_LCD_DC_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define LCD_DC_PORT GPIOC
#define LCD_DC_PIN GPIO_PIN_5

#define LCD_RST_SET_0() HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_RESET)
#define LCD_RST_SET_1() HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET)

#define LCD_DC_SET_0() HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET)
#define LCD_DC_SET_1() HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET)

/* 初始化 */
void GC9A01_GPIO_Init(void);

void GC9A01_Init(void);

void GC9A01_Fill(uint16_t x_1, uint16_t y_1, uint16_t x_2, uint16_t y_2, uint8_t* colors);

#endif
