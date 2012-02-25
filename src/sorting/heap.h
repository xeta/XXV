#ifndef HEAP_H_
#define HEAP_H_

#include "../general.h"
#include <stddef.h>

void max_heapify(void * const root, void * const node, void * const end,
		size_t size, __comporator cmp);

void build_heap(void * const root, void * const end, size_t size,
		__comporator cmp);

#endif /* HEAP_H_ */
