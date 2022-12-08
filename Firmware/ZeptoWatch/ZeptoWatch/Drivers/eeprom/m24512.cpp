#include "m24512.h"

void EEPROM_GPIO_Init() {
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_ROM_I2C_CLK_ENABLE();

	GPIO_InitStructure.Pin = ROM_SCL_PIN | ROM_SDA_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(ROM_I2C_PORT, &GPIO_InitStructure);
	HAL_GPIO_WritePin(ROM_I2C_PORT, ROM_SCL_PIN | ROM_SDA_PIN, GPIO_PIN_SET);
}
