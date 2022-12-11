#ifndef __PIKA_OVERRIDE_H
#define __PIKA_OVERRIDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "PikaPlatform.h"

//int fputc(int ch, FILE *f);

char __platform_getchar(void);

//FILE* __platform_fopen(const char *filename, const char *modes);
//int __platform_fclose(FILE* stream);
//size_t __platform_fwrite(const void* ptr, size_t size, size_t n, FILE* stream);
//size_t __platform_fread(void* ptr, size_t size, size_t n, FILE* stream);

#ifdef __cplusplus
}
#endif

#endif
