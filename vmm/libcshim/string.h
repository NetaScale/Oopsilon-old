#ifndef STRING_H_
#define STRING_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NO_MEMCPY
static inline void *
memcpy(void *dest, const void *src, size_t n);

static inline void *
memcpy(void *dest, const void *src, size_t n)
{
	return __builtin_memcpy(dest, src, n);
}
#endif

static inline void *
memset(void *b, int c, size_t len)
{
	return __builtin_memset(b, c, len);
}

char *strchr(const char *s, int c);

static inline size_t
strlen(const char *str)
{
	return __builtin_strlen(str);
}

#ifdef __cplusplus
}
#endif

#endif /* STRING_H_ */
