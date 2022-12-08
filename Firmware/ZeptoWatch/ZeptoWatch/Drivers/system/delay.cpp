#include "delay.h"

void Delay_us(uint32_t t) {
	uint32_t delay = (HAL_RCC_GetHCLKFreq() / 12000000 * t);
	while (delay --) __NOP();
}

void Delay_ms(uint32_t t) {
	HAL_Delay(t);
}
