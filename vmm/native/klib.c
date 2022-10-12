#define NANOPRINTF_IMPLEMENTATION
#include "nanoprintf.h"
/* the above must come first */

#define NO_MEMCPY
#include <stdio.h>
#include <string.h>

#include "klib.h"

int errno = 0;

/* stdio.h */
int
putchar(int c)
{
	md_kputc(c, NULL);
	return c;
}

int
fprintf(FILE *stream, const char *format, ...)
{
	va_list ap;
	int	r;
	va_start(ap, format);
	r = kvpprintf(format, ap);
	va_end(ap);
	return r;
}

size_t
fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
        for (size_t i = 0; i < size * nmemb; i++)
                md_kputc(*(char*)(ptr + i), NULL);
}

/* stdlib.h */
__attribute((noreturn)) void exit(int status)
{
        kprintf("exit(%d)\n", status);
        for (;;) ;
}


/* string.h */

void *
memcpy(void *dest, const void *src, size_t len)
{
	char	   *d = dest;
	const char *s = src;
	while (len--)
		*d++ = *s++;
	return dest;
}

char *
strchr(const char *s, int c)
{
	do {
		if (*s == c) {
			return (char *)s;
		}
	} while (*s++);
	return (0);
}
