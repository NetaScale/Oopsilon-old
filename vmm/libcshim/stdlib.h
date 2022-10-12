#ifndef STDLIB_H_
#define STDLIB_H_

#include <stddef.h>

#include "native/liballoc.h"

#ifdef __cplusplus
extern "C" {
#endif

__attribute((noreturn)) void exit(int status);

#define malloc(size) liballoc_kmalloc(size)
#define free(ptr) liballoc_kfree(ptr)
#define calloc(nmemb, size) liballoc_kcalloc(nmemb, size)
#define realloc(ptr, size) liballoc_krealloc(ptr, size)
// void *malloc(size_t size);
// void  free(void *ptr);
// void *calloc(size_t nmemb, size_t size);
// void *realloc(void *ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* STDLIB_H_ */
