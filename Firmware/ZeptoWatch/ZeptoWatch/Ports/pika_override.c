#include "pika_override.h"

#include "fatfs.h"

//int fputc(int ch, FILE *f) {
//	uint8_t c = ch;
//	HAL_UART_Transmit(&huart2, &c, 1, 1);
//	return ch;
//}

char __platform_getchar(void) {
	uint8_t ch;
	while (1) {
		if (HAL_OK == HAL_UART_Receive(&huart2, &ch, 1, 0)){
			return ch;
		}
	}
}

//FILE* __platform_fopen(const char *filename, const char *modes) {
//
//}

//int __platform_fclose(FILE *stream) {
//
//}

//size_t __platform_fwrite(const void *ptr, size_t size, size_t n, FILE *stream) {
//
//}

//size_t __platform_fread(void* ptr, size_t size, size_t n, FILE *stream) {
//
//}
