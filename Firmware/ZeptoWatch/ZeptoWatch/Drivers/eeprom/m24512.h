#ifndef __M24512_H
#define __M24512_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#define ROM_ADDR 			0xA0
#define ROM_ADDR_E 			(ROM_ADDR | 0x00)
#define ROM_ADDR_READ 		(ROM_ADDR_E | 0x01)
#define ROM_ADDR_WRITE 		(ROM_ADDR_E)

#define ROM_BLK_NBR 		125
#define ROM_BLK_SIZ 		512 // Bytes

/*
 * ROM_SCL -> PA8
 * ROM_SDA -> PA9
 */

#define __HAL_RCC_ROM_I2C_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define ROM_I2C_PORT GPIOA
#define ROM_SCL_PIN GPIO_PIN_8
#define ROM_SDA_PIN GPIO_PIN_9

#define ROM_SCL_SET_0 HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SCL_PIN, GPIO_PIN_RESET)
#define ROM_SCL_SET_1 HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SCL_PIN, GPIO_PIN_SET)

#define ROM_SDA_SET_0 HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SDA_PIN, GPIO_PIN_RESET)
#define ROM_SDA_SET_1 HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SDA_PIN, GPIO_PIN_SET)
#define ROM_SDA_GET() HAL_GPIO_ReadPin(ROM_I2C_PORT, ROM_SDA_PIN)

extern int ROM_IsReadyFlag;

void ROM_Init();
void ROM_SetReady(int isReady);
int ROM_IsReady();

uint8_t ROM_Read_Bytes(uint8_t *buf, uint16_t addr, uint16_t len);
uint8_t ROM_Write_Bytes(const uint8_t *buf, uint16_t addr, uint16_t len);

void ROM_IIC_Start();
void ROM_IIC_Stop();
void ROM_IIC_Send_Byte(uint8_t byte);
uint8_t ROM_IIC_Read_Byte();
uint8_t ROM_IIC_Wait_Ack();
void ROM_IIC_Ack();
void ROM_IIC_NAck();

#ifdef __cplusplus
}
#endif

#endif
