#include "gc9a01.h"

#include <stdbool.h>

void SPI_SendByte(uint8_t pByte) {
	// while (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_RESET);
	HAL_SPI_Transmit_DMA(&hspi1, &pByte, 1);
}

void SPI_SendCommand(uint8_t pCmd) {
	LCD_DC_SET_0(); // 写命令
	SPI_SendByte(pCmd);
}

void SPI_SendData8(uint16_t pData) {
	LCD_DC_SET_1(); // 写数据
	SPI_SendByte(pData);
}

void SPI_SendData16(uint16_t pData) {
	LCD_DC_SET_1(); // 写数据
	SPI_SendByte(pData >> 8);
	SPI_SendByte(pData);
}

void GC9A01_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_LCD_RST_CLK_ENABLE();
	__HAL_RCC_LCD_DC_CLK_ENABLE();

	/* LCD_SPI in spi.c */

	/* LCD_CS 片选默认接地 */

	/* LCD_RST */
	GPIO_InitStruct.Pin = LCD_RST_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(LCD_RST_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET);

	/* LCD_DC */
	GPIO_InitStruct.Pin = LCD_DC_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(LCD_DC_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);
}

void GC9A01_SetAddress(uint16_t x_1, uint16_t y_1, uint16_t x_2, uint16_t y_2) {
	SPI_SendCommand(0x2A);		// 列地址设置
	SPI_SendData16(x_1);
	SPI_SendData16(x_2);
	SPI_SendCommand(0x2B);		// 行地址设置
	SPI_SendData16(y_1);
	SPI_SendData16(y_2);
	SPI_SendCommand(0x2C);		// 储存器写
}

void GC9A01_Fill(uint16_t x_1, uint16_t y_1, uint16_t x_2, uint16_t y_2, uint8_t* colors) {
	uint8_t idx = 0;
	uint16_t maxNum = 65534;
	uint32_t num = (x_2 - x_1 + 1) * (y_2 - y_1 + 1) * 2;

	GC9A01_SetAddress(x_1, y_1, x_2, y_2);
//	CS_Reset();
	LCD_DC_SET_1(); // 写数据
	bool flag = true;
	while (flag) {
		uint16_t curNum;
		if (num > maxNum) {
			curNum = maxNum;
			num -= curNum;
		} else {
			flag = false;
			curNum = num;
		}
		HAL_SPI_Transmit_DMA(&hspi1, colors + idx * maxNum, curNum);
		idx += 1;
		HAL_Delay(12);
	}
//	CS_Set();
}

void GC9A01_Init(void) {
	LCD_RST_SET_0();					// 复位
	HAL_Delay(100);
	LCD_RST_SET_1();
	HAL_Delay(100);

	SPI_SendCommand(0xEF);
	SPI_SendCommand(0xEB);
	SPI_SendData8(0x14);
	SPI_SendCommand(0xFE);
	SPI_SendCommand(0xEF);
	SPI_SendCommand(0xEB);
	SPI_SendData8(0x14);
	SPI_SendCommand(0x84);
	SPI_SendData8(0x40);
	SPI_SendCommand(0x85);
	SPI_SendData8(0xFF);
	SPI_SendCommand(0x86);
	SPI_SendData8(0xFF);
	SPI_SendCommand(0x87);
	SPI_SendData8(0xFF);
	SPI_SendCommand(0x88);
	SPI_SendData8(0x0A);
	SPI_SendCommand(0x89);
	SPI_SendData8(0x21);
	SPI_SendCommand(0x8A);
	SPI_SendData8(0x00);
	SPI_SendCommand(0x8B);
	SPI_SendData8(0x80);
	SPI_SendCommand(0x8C);
	SPI_SendData8(0x01);
	SPI_SendCommand(0x8D);
	SPI_SendData8(0x01);
	SPI_SendCommand(0x8E);
	SPI_SendData8(0xFF);
	SPI_SendCommand(0x8F);
	SPI_SendData8(0xFF);
	SPI_SendCommand(0xB6);
	SPI_SendData8(0x00);
	SPI_SendData8(0x20);
	SPI_SendCommand(0x36);
	SPI_SendData8(0x08);		// 刷新方向: 0x08 or 0xC8 or 0x68 or 0xA8.
	SPI_SendCommand(0x3A);
	SPI_SendData8(0x05);
	SPI_SendCommand(0x90);
	SPI_SendData8(0x08);
	SPI_SendData8(0x08);
	SPI_SendData8(0x08);
	SPI_SendData8(0x08);
	SPI_SendCommand(0xBD);
	SPI_SendData8(0x06);
	SPI_SendCommand(0xBC);
	SPI_SendData8(0x00);
	SPI_SendCommand(0xFF);
	SPI_SendData8(0x60);
	SPI_SendData8(0x01);
	SPI_SendData8(0x04);
	SPI_SendCommand(0xC3);
	SPI_SendData8(0x13);
	SPI_SendCommand(0xC4);
	SPI_SendData8(0x13);
	SPI_SendCommand(0xC9);
	SPI_SendData8(0x22);
	SPI_SendCommand(0xBE);
	SPI_SendData8(0x11);
	SPI_SendCommand(0xE1);
	SPI_SendData8(0x10);
	SPI_SendData8(0x0E);
	SPI_SendCommand(0xDF);
	SPI_SendData8(0x21);
	SPI_SendData8(0x0c);
	SPI_SendData8(0x02);
	SPI_SendCommand(0xF0);
	SPI_SendData8(0x45);
	SPI_SendData8(0x09);
	SPI_SendData8(0x08);
	SPI_SendData8(0x08);
	SPI_SendData8(0x26);
	SPI_SendData8(0x2A);
	SPI_SendCommand(0xF1);
	SPI_SendData8(0x43);
	SPI_SendData8(0x70);
	SPI_SendData8(0x72);
	SPI_SendData8(0x36);
	SPI_SendData8(0x37);
	SPI_SendData8(0x6F);
	SPI_SendCommand(0xF2);
	SPI_SendData8(0x45);
	SPI_SendData8(0x09);
	SPI_SendData8(0x08);
	SPI_SendData8(0x08);
	SPI_SendData8(0x26);
	SPI_SendData8(0x2A);
	SPI_SendCommand(0xF3);
	SPI_SendData8(0x43);
	SPI_SendData8(0x70);
	SPI_SendData8(0x72);
	SPI_SendData8(0x36);
	SPI_SendData8(0x37);
	SPI_SendData8(0x6F);
	SPI_SendCommand(0xED);
	SPI_SendData8(0x1B);
	SPI_SendData8(0x0B);
	SPI_SendCommand(0xAE);
	SPI_SendData8(0x77);
	SPI_SendCommand(0xCD);
	SPI_SendData8(0x63);
	SPI_SendCommand(0x70);
	SPI_SendData8(0x07);
	SPI_SendData8(0x07);
	SPI_SendData8(0x04);
	SPI_SendData8(0x0E);
	SPI_SendData8(0x0F);
	SPI_SendData8(0x09);
	SPI_SendData8(0x07);
	SPI_SendData8(0x08);
	SPI_SendData8(0x03);
	SPI_SendCommand(0xE8);
	SPI_SendData8(0x34);
	SPI_SendCommand(0x62);
	SPI_SendData8(0x18);
	SPI_SendData8(0x0D);
	SPI_SendData8(0x71);
	SPI_SendData8(0xED);
	SPI_SendData8(0x70);
	SPI_SendData8(0x70);
	SPI_SendData8(0x18);
	SPI_SendData8(0x0F);
	SPI_SendData8(0x71);
	SPI_SendData8(0xEF);
	SPI_SendData8(0x70);
	SPI_SendData8(0x70);
	SPI_SendCommand(0x63);
	SPI_SendData8(0x18);
	SPI_SendData8(0x11);
	SPI_SendData8(0x71);
	SPI_SendData8(0xF1);
	SPI_SendData8(0x70);
	SPI_SendData8(0x70);
	SPI_SendData8(0x18);
	SPI_SendData8(0x13);
	SPI_SendData8(0x71);
	SPI_SendData8(0xF3);
	SPI_SendData8(0x70);
	SPI_SendData8(0x70);
	SPI_SendCommand(0x64);
	SPI_SendData8(0x28);
	SPI_SendData8(0x29);
	SPI_SendData8(0xF1);
	SPI_SendData8(0x01);
	SPI_SendData8(0xF1);
	SPI_SendData8(0x00);
	SPI_SendData8(0x07);
	SPI_SendCommand(0x66);
	SPI_SendData8(0x3C);
	SPI_SendData8(0x00);
	SPI_SendData8(0xCD);
	SPI_SendData8(0x67);
	SPI_SendData8(0x45);
	SPI_SendData8(0x45);
	SPI_SendData8(0x10);
	SPI_SendData8(0x00);
	SPI_SendData8(0x00);
	SPI_SendData8(0x00);
	SPI_SendCommand(0x67);
	SPI_SendData8(0x00);
	SPI_SendData8(0x3C);
	SPI_SendData8(0x00);
	SPI_SendData8(0x00);
	SPI_SendData8(0x00);
	SPI_SendData8(0x01);
	SPI_SendData8(0x54);
	SPI_SendData8(0x10);
	SPI_SendData8(0x32);
	SPI_SendData8(0x98);
	SPI_SendCommand(0x74);
	SPI_SendData8(0x10);
	SPI_SendData8(0x85);
	SPI_SendData8(0x80);
	SPI_SendData8(0x00);
	SPI_SendData8(0x00);
	SPI_SendData8(0x4E);
	SPI_SendData8(0x00);
	SPI_SendCommand(0x98);
	SPI_SendData8(0x3e);
	SPI_SendData8(0x07);
	SPI_SendCommand(0x35);
	SPI_SendCommand(0x21);
	SPI_SendCommand(0x11);
	HAL_Delay(120);
	SPI_SendCommand(0x29);
	HAL_Delay(20);

	// 打开背光 ...
}
