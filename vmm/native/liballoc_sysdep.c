#include "liballoc.h"

int
liballoc_lock()
{
	//mutex_lock(&alloclock);
	return 0;
}

int
liballoc_unlock()
{
	//mutex_unlock(&alloclock);
	return 0;
}

void *
liballoc_alloc(size_t pages)
{
	//void *addr = vm_kalloc(pages, false);
	//return addr;
        return NULL;
}

int
liballoc_free(void *ptr, size_t pages)
{
	//vm_kfree(ptr, pages);
	return 0;
}
