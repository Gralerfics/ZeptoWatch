#ifndef __M24512_H
#define __M24512_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/*
 * ROM_SCL -> PA8
 * ROM_SDA -> PA9
 */

#define __HAL_RCC_ROM_I2C_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define ROM_I2C_PORT GPIOA
#define ROM_SCL_PIN GPIO_PIN_8
#define ROM_SDA_PIN GPIO_PIN_9

void EEPROM_GPIO_Init();

#ifdef __cplusplus
}
#endif

#endif
