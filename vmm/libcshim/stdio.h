#ifndef STDIO_H_
#define STDIO_H_

#include <stddef.h>
#include <stdint.h>

#include "native/klib.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct file FILE;

#define printf(...) kprintf(__VA_ARGS__)
#define vpprintf(...) kvpprintf(__VA_ARGS__)
#define snprintf(...) ksnprintf(__VA_ARGS__)
#define sprintf(str, ...) ksnprintf(str, UINT32_MAX, __VA_ARGS__)

int    putchar(int c);
int    fprintf(FILE *stream, const char *format, ...);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

#define EOF (-1)
#define stdin (FILE *)1
#define stdout (FILE *)1
#define stderr (FILE *)2

#ifdef __cplusplus
}
#endif

#endif /* STDIO_H_ */
