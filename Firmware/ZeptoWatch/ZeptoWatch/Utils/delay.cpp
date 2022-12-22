#include "delay.h"

#include "tim.h"

void Delay_us(uint32_t t) {
	uint32_t delay = (HAL_RCC_GetHCLKFreq() / 6000000 * t);
	while (delay --) __NOP();

//	__HAL_TIM_SET_COUNTER(&htim7, 0);
//	__HAL_TIM_ENABLE(&htim7);
//	while (__HAL_TIM_GET_COUNTER(&htim7) < t);
//	__HAL_TIM_DISABLE(&htim7);

//	int last, curr, val, temp;
//	while (t != 0) {
//		temp = t > 900 ? 900 : t;
//		last = SysTick -> VAL;
//		curr = last - SystemCoreClock / 1000000 * temp;
//		if (curr >= 0) {
//			do { val = SysTick->VAL; } while ((val < last) && (val >= curr));
//		} else {
//			curr += SystemCoreClock / 1000;
//			do { val = SysTick->VAL; } while ((val <= last) || (val > curr));
//		}
//		t -= temp;
//	}
}

void Delay_ms(uint32_t t) {
	Delay_us(1000 * t); // HAL_Delay 依赖于 HAL Tick, 无法在中断之类的场景使用
}
