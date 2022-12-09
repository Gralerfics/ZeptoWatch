#include "m24512.h"

#include "delay.h"

int ROM_IsReadyFlag = 1;

void ROM_Init() {
	ROM_SetReady(0);

	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_ROM_I2C_CLK_ENABLE();

	GPIO_InitStructure.Pin = ROM_SCL_PIN | ROM_SDA_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(ROM_I2C_PORT, &GPIO_InitStructure);
	HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SCL_PIN | ROM_SDA_PIN, GPIO_PIN_SET);

	ROM_SetReady(1);
}

void ROM_SetReady(int isReady) {
	ROM_IsReadyFlag = isReady;
}

int ROM_IsReady() {
	return ROM_IsReadyFlag;
}

uint8_t ROM_Read_Bytes(uint8_t *buf, uint16_t addr, uint16_t len) {
	ROM_SetReady(0);

	uint16_t i;

	ROM_IIC_Start();
	ROM_IIC_Send_Byte(ROM_ADDR_WRITE);
	if (ROM_IIC_Wait_Ack() != 0) {
		ROM_IIC_Stop();
		return 0;
	}

	ROM_IIC_Send_Byte(addr >> 8);
	if (ROM_IIC_Wait_Ack() != 0) {
		ROM_IIC_Stop();
		return 0;
	}
	ROM_IIC_Send_Byte(addr);
	if (ROM_IIC_Wait_Ack() != 0) {
		ROM_IIC_Stop();
		return 0;
	}

	ROM_IIC_Start();
	ROM_IIC_Send_Byte(ROM_ADDR_READ);
	if (ROM_IIC_Wait_Ack() != 0) {
		ROM_IIC_Stop();
		return 0;
	}

	for (i = 0; i < len; i ++) {
		buf[i] = ROM_IIC_Read_Byte();
		if (i != len - 1) ROM_IIC_Ack(); else ROM_IIC_NAck();
	}
	ROM_IIC_Stop();

	ROM_SetReady(1);

	return 1;
}

uint8_t ROM_Write_Bytes(const uint8_t *buf, uint16_t addr, uint16_t len) {
	ROM_SetReady(0);

	uint16_t i, m, usAddr = addr;

	for (i = 0; i < len; i ++) {
//		if ((i == 0) || (usAddr & (ROM_BLK_SIZ - 1)) == 0) {
//			ROM_IIC_Stop();
//
//			for (m = 0; m < 1000; m ++) {
//				ROM_IIC_Start();
//				ROM_IIC_Send_Byte(ROM_ADDR_WRITE);
//				if (ROM_IIC_Wait_Ack() == 0) break;
//			}
//			if (m == 1000) {
//				ROM_IIC_Stop();
//				return 0;
//			}
//
//			ROM_IIC_Send_Byte(usAddr >> 8);
//			if (ROM_IIC_Wait_Ack() != 0) {
//				ROM_IIC_Stop();
//				return 0;
//			}
//			ROM_IIC_Send_Byte(usAddr);
//			if (ROM_IIC_Wait_Ack() != 0) {
//				ROM_IIC_Stop();
//				return 0;
//			}
//		}
//
//		ROM_IIC_Send_Byte(buf[i]);
//		if (ROM_IIC_Wait_Ack() != 0) {
//			ROM_IIC_Stop();
//			return 0;
//		}

		for (m = 0; m < 1000; m ++) {
			ROM_IIC_Start();
			ROM_IIC_Send_Byte(ROM_ADDR_WRITE);
			if (ROM_IIC_Wait_Ack() == 0) break;
		}
		if (m == 1000) {
			ROM_IIC_Stop();
			return 0;
		}

		ROM_IIC_Send_Byte(usAddr >> 8);
		if (ROM_IIC_Wait_Ack() != 0) {
			ROM_IIC_Stop();
			return 0;
		}
		ROM_IIC_Send_Byte(usAddr);
		if (ROM_IIC_Wait_Ack() != 0) {
			ROM_IIC_Stop();
			return 0;
		}

		ROM_IIC_Send_Byte(buf[i]);
		if (ROM_IIC_Wait_Ack() != 0) {
			ROM_IIC_Stop();
			return 0;
		}

		ROM_IIC_Stop();

		usAddr ++;
	}
//	ROM_IIC_Stop();

	for (m = 0; m < 1000; m ++) {
		ROM_IIC_Start();
		ROM_IIC_Send_Byte(ROM_ADDR_WRITE);
		if (ROM_IIC_Wait_Ack() == 0) break;
	}
	if (m == 1000) {
		ROM_IIC_Stop();
		return 0;
	}
	ROM_IIC_Stop();

	ROM_SetReady(1);

	return 1;
}

void ROM_SDA_INPUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_ROM_I2C_CLK_ENABLE();

	GPIO_Init.Pin = ROM_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_INPUT;
	GPIO_Init.Pull = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(ROM_I2C_PORT, &GPIO_Init);
}

void ROM_SDA_OUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_ROM_I2C_CLK_ENABLE();

	GPIO_Init.Pin = ROM_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(ROM_I2C_PORT, &GPIO_Init);
}

void ROM_IIC_Delay() {
	Delay_us(2);
}

void ROM_IIC_Start() {
	ROM_SDA_OUT();
	ROM_SDA_SET_1, ROM_IIC_Delay();
	ROM_SCL_SET_1, ROM_IIC_Delay();
	ROM_SDA_SET_0, ROM_IIC_Delay();
	ROM_SCL_SET_0, ROM_IIC_Delay();
}

void ROM_IIC_Stop() {
	ROM_SDA_OUT();
	ROM_SCL_SET_0, ROM_IIC_Delay();
	ROM_SDA_SET_0, ROM_IIC_Delay();
	ROM_SCL_SET_1, ROM_IIC_Delay();
	ROM_SDA_SET_1, ROM_IIC_Delay();
}

void ROM_IIC_Send_Byte(uint8_t byte) {
	ROM_SDA_OUT();
	ROM_SCL_SET_0;
	for (uint8_t i = 0; i < 8; i ++) {
		if (byte & 0x80) {
			ROM_SDA_SET_1;
		} else {
			ROM_SDA_SET_0;
		}
		ROM_IIC_Delay();
		ROM_SCL_SET_1, ROM_IIC_Delay();
		ROM_SCL_SET_0, ROM_IIC_Delay();
		if (i == 7) ROM_SDA_SET_1, ROM_IIC_Delay();
		byte <<= 1;
	}
}

uint8_t ROM_IIC_Read_Byte() {
	uint8_t receive = 0;
	ROM_SDA_INPUT();
	for (uint8_t i = 0; i < 8; i ++) {
		receive <<= 1;
		ROM_SCL_SET_1, ROM_IIC_Delay();
		if (ROM_SDA_GET()) receive ++;
		ROM_SCL_SET_0, ROM_IIC_Delay();
	}
	return receive;
}

uint8_t ROM_IIC_Wait_Ack() {
	uint8_t ucErrTime = 0;
	ROM_SDA_INPUT();
	ROM_SDA_SET_1, ROM_IIC_Delay();
	ROM_SCL_SET_1, ROM_IIC_Delay();
	while (ROM_SDA_GET()) {
		ucErrTime++;
		if (ucErrTime > 250) {
			ROM_IIC_Stop();
			return 1;
		}
	}
	ROM_SCL_SET_0, ROM_IIC_Delay();
	ROM_SDA_OUT();
	return 0;
}

void ROM_IIC_Ack() {
	ROM_SDA_OUT();
	ROM_SDA_SET_0, ROM_IIC_Delay();
	ROM_SCL_SET_1, ROM_IIC_Delay();
	ROM_SCL_SET_0, ROM_IIC_Delay();
	ROM_SDA_SET_1, ROM_IIC_Delay();
}

void ROM_IIC_NAck() {
	ROM_SDA_OUT();
	ROM_SDA_SET_1, ROM_IIC_Delay();
	ROM_SCL_SET_1, ROM_IIC_Delay();
	ROM_SCL_SET_0, ROM_IIC_Delay();
}
