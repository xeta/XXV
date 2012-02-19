#include "heap.h"
#include <iostream>

void* heap_parent(const void* root, const void* node, const size_t size) {
	size_t dif = ((char*) node - (char*) root - size) >> 0x01;
	return ((char*) root) + dif - dif % size;
}

void* heap_left(void* root, void* node, const size_t size) {
	return ((char*) root) + (((char*) node - (char*) root) << 0x01) + size;
}

void* heap_right(void* root, void* node, size_t size) {
	return (char*) root + (((char*) node - (char*) root) << 0x01) + (size << 0x01);
}

//void max_heapify(heap_type* root, heap_type* node, size_t* size) {
//	heap_type* left = heap_left(root, node);
//	heap_type* right = heap_right(root, node);
//	heap_type* largest;
//	if (left - root < size && *node < *left) {
//		largest = left;
//	} else {
//		largest = node;
//	}
//	if (right - root < size && *node < *right) {
//		largest = right;
//	}
//	if (largest != node) {
//		heap_type buf = *node;
//		*node = *largest;
//		*largest = buf;
//		max_heapify(root, largest, size);
//	}
//
//}
