#ifndef ASSERT_H_
#define ASSERT_H_

#include "native/klib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define fatal(...)                      \
	{                               \
		kprintf(__VA_ARGS__);   \
		while (1) {             \
			__asm__("cli"); \
		}                       \
	}

#define kassert(...)                                                   \
	{                                                              \
		if (!(__VA_ARGS__))                                    \
			fatal("assertion failed: %s\n", #__VA_ARGS__); \
	}

#ifdef __cplusplus
}
#endif

#endif /* ASSERT_H_ */
