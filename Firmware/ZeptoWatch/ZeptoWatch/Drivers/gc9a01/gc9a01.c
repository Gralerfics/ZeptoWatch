#include "gc9a01.h"

#include <stdbool.h>

void GC9A01_SPI_SendByte(uint8_t pByte) {
	HAL_SPI_Transmit_DMA(&hspi1, &pByte, 1);
}

void GC9A01_SPI_SendCommand(uint8_t pCmd) {
	LCD_DC_SET_0(); // 写命令
	GC9A01_SPI_SendByte(pCmd);
}

void GC9A01_SPI_SendData8(uint16_t pData) {
	LCD_DC_SET_1(); // 写数据
	GC9A01_SPI_SendByte(pData);
}

void GC9A01_SPI_SendData16(uint16_t pData) {
	LCD_DC_SET_1(); // 写数据
	GC9A01_SPI_SendByte(pData >> 8);
	GC9A01_SPI_SendByte(pData);
}

void GC9A01_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_LCD_RST_CLK_ENABLE();
	__HAL_RCC_LCD_DC_CLK_ENABLE();

	/* LCD_SPI in spi.c */
		/* IMPORTANT! SLK 或 SDA 需要上拉一个！ (?) */
		/* 或 spi.h 中要是 "GPIO_InitStruct.Pull = GPIO_PULLUP;" */

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
	GC9A01_SPI_SendCommand(0x2A);		// 列地址设置
	GC9A01_SPI_SendData16(x_1);
	GC9A01_SPI_SendData16(x_2);
	GC9A01_SPI_SendCommand(0x2B);		// 行地址设置
	GC9A01_SPI_SendData16(y_1);
	GC9A01_SPI_SendData16(y_2);
	GC9A01_SPI_SendCommand(0x2C);		// 储存器写
}

void GC9A01_Fill(uint16_t x_1, uint16_t y_1, uint16_t x_2, uint16_t y_2, uint16_t *colors) {
	uint8_t idx = 0;
	uint16_t maxNum = 65534;
	uint32_t num = (x_2 - x_1 + 1) * (y_2 - y_1 + 1) * 2;

	GC9A01_SetAddress(x_1, y_1, x_2, y_2);
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
		HAL_SPI_Transmit_DMA(&hspi1, (uint8_t *) (colors + idx * maxNum), curNum);
		idx += 1;
		while (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_BUSY_TX);
	}
}

void GC9A01_Init(void) {
	LCD_RST_SET_0();					// 复位
	HAL_Delay(100);
	LCD_RST_SET_1();
	HAL_Delay(100);

	GC9A01_SPI_SendCommand(0xEF);
	GC9A01_SPI_SendCommand(0xEB);
	GC9A01_SPI_SendData8(0x14);
	GC9A01_SPI_SendCommand(0xFE);
	GC9A01_SPI_SendCommand(0xEF);
	GC9A01_SPI_SendCommand(0xEB);
	GC9A01_SPI_SendData8(0x14);
	GC9A01_SPI_SendCommand(0x84);
	GC9A01_SPI_SendData8(0x40);
	GC9A01_SPI_SendCommand(0x85);
	GC9A01_SPI_SendData8(0xFF);
	GC9A01_SPI_SendCommand(0x86);
	GC9A01_SPI_SendData8(0xFF);
	GC9A01_SPI_SendCommand(0x87);
	GC9A01_SPI_SendData8(0xFF);
	GC9A01_SPI_SendCommand(0x88);
	GC9A01_SPI_SendData8(0x0A);
	GC9A01_SPI_SendCommand(0x89);
	GC9A01_SPI_SendData8(0x21);
	GC9A01_SPI_SendCommand(0x8A);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendCommand(0x8B);
	GC9A01_SPI_SendData8(0x80);
	GC9A01_SPI_SendCommand(0x8C);
	GC9A01_SPI_SendData8(0x01);
	GC9A01_SPI_SendCommand(0x8D);
	GC9A01_SPI_SendData8(0x01);
	GC9A01_SPI_SendCommand(0x8E);
	GC9A01_SPI_SendData8(0xFF);
	GC9A01_SPI_SendCommand(0x8F);
	GC9A01_SPI_SendData8(0xFF);
	GC9A01_SPI_SendCommand(0xB6);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x20);

	GC9A01_SPI_SendCommand(0x36);
	GC9A01_SPI_SendData8(0xA8);		// 刷新方向: 0x08 (朝上) or 0xC8 (朝下) or 0x68 (朝右) or 0xA8 (朝左). 注意触摸方面需要相应修改!

	GC9A01_SPI_SendCommand(0x3A);
	GC9A01_SPI_SendData8(0x05);
	GC9A01_SPI_SendCommand(0x90);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendCommand(0xBD);
	GC9A01_SPI_SendData8(0x06);
	GC9A01_SPI_SendCommand(0xBC);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendCommand(0xFF);
	GC9A01_SPI_SendData8(0x60);
	GC9A01_SPI_SendData8(0x01);
	GC9A01_SPI_SendData8(0x04);
	GC9A01_SPI_SendCommand(0xC3);
	GC9A01_SPI_SendData8(0x13);
	GC9A01_SPI_SendCommand(0xC4);
	GC9A01_SPI_SendData8(0x13);
	GC9A01_SPI_SendCommand(0xC9);
	GC9A01_SPI_SendData8(0x22);
	GC9A01_SPI_SendCommand(0xBE);
	GC9A01_SPI_SendData8(0x11);
	GC9A01_SPI_SendCommand(0xE1);
	GC9A01_SPI_SendData8(0x10);
	GC9A01_SPI_SendData8(0x0E);
	GC9A01_SPI_SendCommand(0xDF);
	GC9A01_SPI_SendData8(0x21);
	GC9A01_SPI_SendData8(0x0c);
	GC9A01_SPI_SendData8(0x02);
	GC9A01_SPI_SendCommand(0xF0);
	GC9A01_SPI_SendData8(0x45);
	GC9A01_SPI_SendData8(0x09);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x26);
	GC9A01_SPI_SendData8(0x2A);
	GC9A01_SPI_SendCommand(0xF1);
	GC9A01_SPI_SendData8(0x43);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x72);
	GC9A01_SPI_SendData8(0x36);
	GC9A01_SPI_SendData8(0x37);
	GC9A01_SPI_SendData8(0x6F);
	GC9A01_SPI_SendCommand(0xF2);
	GC9A01_SPI_SendData8(0x45);
	GC9A01_SPI_SendData8(0x09);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x26);
	GC9A01_SPI_SendData8(0x2A);
	GC9A01_SPI_SendCommand(0xF3);
	GC9A01_SPI_SendData8(0x43);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x72);
	GC9A01_SPI_SendData8(0x36);
	GC9A01_SPI_SendData8(0x37);
	GC9A01_SPI_SendData8(0x6F);
	GC9A01_SPI_SendCommand(0xED);
	GC9A01_SPI_SendData8(0x1B);
	GC9A01_SPI_SendData8(0x0B);
	GC9A01_SPI_SendCommand(0xAE);
	GC9A01_SPI_SendData8(0x77);
	GC9A01_SPI_SendCommand(0xCD);
	GC9A01_SPI_SendData8(0x63);
	GC9A01_SPI_SendCommand(0x70);
	GC9A01_SPI_SendData8(0x07);
	GC9A01_SPI_SendData8(0x07);
	GC9A01_SPI_SendData8(0x04);
	GC9A01_SPI_SendData8(0x0E);
	GC9A01_SPI_SendData8(0x0F);
	GC9A01_SPI_SendData8(0x09);
	GC9A01_SPI_SendData8(0x07);
	GC9A01_SPI_SendData8(0x08);
	GC9A01_SPI_SendData8(0x03);
	GC9A01_SPI_SendCommand(0xE8);
	GC9A01_SPI_SendData8(0x34);
	GC9A01_SPI_SendCommand(0x62);
	GC9A01_SPI_SendData8(0x18);
	GC9A01_SPI_SendData8(0x0D);
	GC9A01_SPI_SendData8(0x71);
	GC9A01_SPI_SendData8(0xED);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x18);
	GC9A01_SPI_SendData8(0x0F);
	GC9A01_SPI_SendData8(0x71);
	GC9A01_SPI_SendData8(0xEF);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendCommand(0x63);
	GC9A01_SPI_SendData8(0x18);
	GC9A01_SPI_SendData8(0x11);
	GC9A01_SPI_SendData8(0x71);
	GC9A01_SPI_SendData8(0xF1);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x18);
	GC9A01_SPI_SendData8(0x13);
	GC9A01_SPI_SendData8(0x71);
	GC9A01_SPI_SendData8(0xF3);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendData8(0x70);
	GC9A01_SPI_SendCommand(0x64);
	GC9A01_SPI_SendData8(0x28);
	GC9A01_SPI_SendData8(0x29);
	GC9A01_SPI_SendData8(0xF1);
	GC9A01_SPI_SendData8(0x01);
	GC9A01_SPI_SendData8(0xF1);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x07);
	GC9A01_SPI_SendCommand(0x66);
	GC9A01_SPI_SendData8(0x3C);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0xCD);
	GC9A01_SPI_SendData8(0x67);
	GC9A01_SPI_SendData8(0x45);
	GC9A01_SPI_SendData8(0x45);
	GC9A01_SPI_SendData8(0x10);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendCommand(0x67);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x3C);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x01);
	GC9A01_SPI_SendData8(0x54);
	GC9A01_SPI_SendData8(0x10);
	GC9A01_SPI_SendData8(0x32);
	GC9A01_SPI_SendData8(0x98);
	GC9A01_SPI_SendCommand(0x74);
	GC9A01_SPI_SendData8(0x10);
	GC9A01_SPI_SendData8(0x85);
	GC9A01_SPI_SendData8(0x80);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendData8(0x4E);
	GC9A01_SPI_SendData8(0x00);
	GC9A01_SPI_SendCommand(0x98);
	GC9A01_SPI_SendData8(0x3e);
	GC9A01_SPI_SendData8(0x07);
	GC9A01_SPI_SendCommand(0x35);
	GC9A01_SPI_SendCommand(0x21);
	GC9A01_SPI_SendCommand(0x11);
	HAL_Delay(120);
	GC9A01_SPI_SendCommand(0x29);
	HAL_Delay(20);

	// 打开背光 ...
}
