#ifndef HEAP_H_
#define HEAP_H_

//#include <stddef.h>
#include <stdlib.h>

void* heap_parent(const void* root, const void* node, const size_t size);
void* heap_left(const void* root, const void* node, size_t size);
void* heap_right(const void* root, const void* node, size_t size);
void max_heapify(const void* root, const void* node, const size_t size, size_t total,
		__compar_fn_t cmp);
void max_heapify(const void* root, const void* node, const void* end,
		const size_t size, __compar_fn_t cmp);
void build_heap(const void* root, size_t size, size_t total, __compar_fn_t cmp);
#endif /* HEAP_H_ */
