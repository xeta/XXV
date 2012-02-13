#include "heap.h"

heap_type* heap_left(heap_type* root, heap_type* node){
	return root + ((node - root) << 0x01) + 1;
}

heap_type* heap_right(heap_type* root, heap_type* node){
	return root + ((node - root) << 0x01) + 2;
}

heap_type* heap_parent(heap_type* root, heap_type* node){
	return root + ((node - root - 1) >> 0x01);
}
