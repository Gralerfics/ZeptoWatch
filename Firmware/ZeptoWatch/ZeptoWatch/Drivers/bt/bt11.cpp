#include "bt11.h"

#include "delay.h"

void BT11_Init() {
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	__HAL_RCC_BT_RST_CLK_ENABLE();

	GPIO_InitStructure.Pin = BT_RST_Pin;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(BT_RST_GPIO_Port, &GPIO_InitStructure);

	HAL_GPIO_WritePin(BT_RST_GPIO_Port, BT_RST_Pin, GPIO_PIN_SET);

	BT11_Reset();
}

void BT11_Reset() {
	HAL_GPIO_WritePin(BT_RST_GPIO_Port, BT_RST_Pin, GPIO_PIN_RESET);
	Delay_us(500);
	HAL_GPIO_WritePin(BT_RST_GPIO_Port, BT_RST_Pin, GPIO_PIN_SET);
}
