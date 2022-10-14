#include "oled.h"
#include "oled_font.h"

#include <cmath>

#include "delay.h"

void OLED_GPIO_Init() {
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_OLED_I2C_CLK_ENABLE();

	GPIO_InitStruct.Pin = OLED_I2C_SCL_PIN | OLED_I2C_SDA_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(OLED_I2C_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN | OLED_I2C_SDA_PIN, GPIO_PIN_SET);
}

void OLED_Initialize() {
	OLED_GPIO_Init();

	for (uint32_t i = 0; i < 10000000; i ++);

	OLED_I2C_SendCommand(0xAE);

	OLED_I2C_SendCommand(0xD5);
	OLED_I2C_SendCommand(0x80);

	OLED_I2C_SendCommand(0xA8);
	OLED_I2C_SendCommand(0x3F);

	OLED_I2C_SendCommand(0xD3);
	OLED_I2C_SendCommand(0x00);

	OLED_I2C_SendCommand(0x40);

	OLED_I2C_SendCommand(0xA1);

	OLED_I2C_SendCommand(0xC8);

	OLED_I2C_SendCommand(0xDA);
	OLED_I2C_SendCommand(0x12);

	OLED_I2C_SendCommand(0x81);
	OLED_I2C_SendCommand(0xCF);

	OLED_I2C_SendCommand(0xD9);
	OLED_I2C_SendCommand(0xF1);

	OLED_I2C_SendCommand(0xDB);
	OLED_I2C_SendCommand(0x30);

	OLED_I2C_SendCommand(0xA4);

	OLED_I2C_SendCommand(0xA6);

	OLED_I2C_SendCommand(0x8D);
	OLED_I2C_SendCommand(0x14);

	OLED_I2C_SendCommand(0xAF);

	OLED_ClearCanvas();
}

void OLED_ClearCanvas() {
	for (uint8_t j = 0; j < 8; j++) {
		OLED_SetCursor(0, j);
		for (uint8_t i = 0; i < 128; i++) OLED_I2C_SendData(0x00);
	}
}

void OLED_SetCursor(uint8_t pX, uint8_t pY) {
	OLED_I2C_SendCommand(0xB0 | pY);
	OLED_I2C_SendCommand(0x10 | ((pX & 0xF0) >> 4));
	OLED_I2C_SendCommand(0x00 | (pX & 0x0F));
}

void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char) {
	uint8_t i;
	OLED_SetCursor((Column - 1) * 8, (Line - 1) * 2);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++) {
		OLED_I2C_SendData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Column - 1) * 8, (Line - 1) * 2 + 1);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++) {
		OLED_I2C_SendData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

void OLED_ShowString(uint8_t Line, uint8_t Column, char* String) {
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++) OLED_ShowChar(Line, Column + i, String[i]);
}

void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length) {
	uint8_t i;
	for (i = 0; i < Length; i++) OLED_ShowChar(Line, Column + i, Number / int(std::pow(10, Length - i - 1)) % 10 + '0');
}

void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length) {
	uint8_t i;
	uint32_t num;
	if (Number >= 0) {
		OLED_ShowChar(Line, Column, '+');
		num = Number;
	} else {
		OLED_ShowChar(Line, Column, '-');
		num = -Number;
	}
	for (i = 0; i < Length; i++) OLED_ShowChar(Line, Column + i + 1, num / int(std::pow(10, Length - i - 1)) % 10 + '0');
}

void OLED_ShowFloat(uint8_t Line, uint8_t Column, double Number, uint8_t LengthLeft, uint8_t LengthRight) {
	uint32_t left;
	left = (uint32_t) std::floor(Number);
	OLED_ShowNum(Line, Column, left, LengthLeft);
	OLED_ShowChar(Line, Column + LengthLeft, '.');
	OLED_ShowNum(Line, Column + LengthLeft + 1,
				 (uint32_t) std::floor((Number - (double) left) * std::pow(10, LengthRight)), LengthRight);
}

void OLED_ShowSignedFloat(uint8_t Line, uint8_t Column, double Number, uint8_t LengthLeft, uint8_t LengthRight) {
	double num;
	if (Number >= 0) {
		OLED_ShowChar(Line, Column, '+');
		num = Number;
	} else {
		OLED_ShowChar(Line, Column, '-');
		num = -Number;
	}
	OLED_ShowFloat(Line, Column + 1, num, LengthLeft, LengthRight);
}

#define OLED_I2C_DELAY_US 1

void OLED_I2C_EnableTransmission() {
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SDA_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_SET);
	delay_us(OLED_I2C_DELAY_US);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SDA_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_RESET);
	delay_us(OLED_I2C_DELAY_US);
}

void OLED_I2C_DisableTransmission() {
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SDA_PIN, GPIO_PIN_RESET);
	delay_us(OLED_I2C_DELAY_US);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_SET);
	delay_us(OLED_I2C_DELAY_US);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SDA_PIN, GPIO_PIN_SET);
	delay_us(OLED_I2C_DELAY_US);
}

void OLED_I2C_SendByte(uint8_t pByte) {
	for (uint8_t i = 0; i < 8; i ++) {
		HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SDA_PIN, static_cast<GPIO_PinState>(pByte & (0x80 >> i)));
		delay_us(OLED_I2C_DELAY_US);
		HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_SET);
		delay_us(OLED_I2C_DELAY_US);
		HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_RESET);
		delay_us(OLED_I2C_DELAY_US);
	}
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_SET);
	delay_us(OLED_I2C_DELAY_US);
	HAL_GPIO_WritePin(OLED_I2C_PORT, OLED_I2C_SCL_PIN, GPIO_PIN_RESET);
	delay_us(OLED_I2C_DELAY_US);
}

void OLED_I2C_SendCommand(uint8_t pCmd) {
	OLED_I2C_EnableTransmission();
	OLED_I2C_SendByte(OLED_I2C_ADDRESS);
	OLED_I2C_SendByte(0x00);
	OLED_I2C_SendByte(pCmd);
	OLED_I2C_DisableTransmission();
}

void OLED_I2C_SendData(uint8_t pData) {
	OLED_I2C_EnableTransmission();
	OLED_I2C_SendByte(OLED_I2C_ADDRESS);
	OLED_I2C_SendByte(0x40);
	OLED_I2C_SendByte(pData);
	OLED_I2C_DisableTransmission();
}
