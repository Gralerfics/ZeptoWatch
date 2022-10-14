#ifndef __OLED_VISUAL_IIC_H
#define __OLED_VISUAL_IIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

//#include "stm32f4xx_hal.h"

/*
 * OLED_SCL -> PB3
 * OLED_SDA -> PB4
 */

/* 0.96', 128x64 */
// 需要相应的 GPIO 引脚已经配置好开漏输出以及其他项
#define __HAL_RCC_OLED_I2C_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define OLED_I2C_PORT GPIOB
#define OLED_I2C_SCL_PIN GPIO_PIN_3
#define OLED_I2C_SDA_PIN GPIO_PIN_4
#define OLED_I2C_ADDRESS 0x78

void OLED_GPIO_Init();

void OLED_Initialize();

void OLED_ClearCanvas();

void OLED_SetCursor(uint8_t pX, uint8_t pY);

void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);

void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);

void OLED_ShowFloat(uint8_t Line, uint8_t Column, double Number, uint8_t LengthLeft, uint8_t LengthRight);

void OLED_ShowSignedFloat(uint8_t Line, uint8_t Column, double Number, uint8_t LengthLeft, uint8_t LengthRight);

void OLED_I2C_EnableTransmission();

void OLED_I2C_DisableTransmission();

void OLED_I2C_SendByte(uint8_t pByte);

void OLED_I2C_SendCommand(uint8_t pCmd);

void OLED_I2C_SendData(uint8_t pData);

#ifdef __cplusplus
}
#endif

#endif
