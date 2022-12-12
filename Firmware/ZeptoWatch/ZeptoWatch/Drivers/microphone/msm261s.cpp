#include "msm261s.h"

uint32_t Microphone_DMA_Buffer[4];
int Microphone_Value_32 = 0;

void Microphone_StartSampling() {
	HAL_I2S_Receive_DMA(&hi2s3, (uint16_t *) Microphone_DMA_Buffer, 4);
}

void Microphone_StopSampling() {
	HAL_I2S_DMAStop(&hi2s3);
}

int Microphone_GetSampleData() {
	return Microphone_Value_32;
}
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s) {
	if (hi2s == &hi2s3) {
		uint32_t val24 = (Microphone_DMA_Buffer[0] << 8) + (Microphone_DMA_Buffer[1] >> 8);
		if (val24 & 0x800000) {
			// Negative
			Microphone_Value_32 = 0xFF000000 | val24;
		} else {
			// Positive
			Microphone_Value_32 = val24;
		}
	}
}
