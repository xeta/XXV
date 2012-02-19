#ifndef HEAP_H_
#define HEAP_H_

#include <stddef.h>

void* heap_parent(const void* root, const  void* node, const size_t size);
void* heap_left(void* root, void* node, size_t size);
void* heap_right(void* root, void* node, size_t size);

#endif /* HEAP_H_ */
