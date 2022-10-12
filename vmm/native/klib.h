/*
 * Kernel library routines.
 */

#ifndef KLIB_H_
#define KLIB_H_

#include "nanoprintf.h"

#ifdef __cplusplus
extern "C" {
#endif

#define kprintf(...) npf_pprintf(md_kputc, NULL, __VA_ARGS__)
#define kvpprintf(...) npf_vpprintf(md_kputc, NULL, __VA_ARGS__)
#define ksnprintf(...) npf_snprintf(__VA_ARGS__)

void md_kputc(int ch, void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* KLIB_H_ */
