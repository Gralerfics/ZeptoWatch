#include "PikaPlatform.h"

#include "common.h"
//#include "fatfs.h"

char __platform_getchar(void) {
	uint8_t ch;
	while (1) {
		if (HAL_OK == HAL_UART_Receive(&huart6, &ch, 1, 0)) {
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
