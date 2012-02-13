#include "heap.h"

struct heap {
	heap_type* root;
	unsigned int size;
};

heap_type* heap_left(heap_type* root, heap_type* node) {
	return root + ((node - root) << 0x01) + 1;
}

heap_type* heap_right(heap_type* root, heap_type* node) {
	return root + ((node - root) << 0x01) + 2;
}

heap_type* heap_parent(heap_type* root, heap_type* node) {
	return root + ((node - root - 1) >> 0x01);
}

void max_heapify(heap x, heap_type* node) {
	heap_type* left = heap_left(x.root, node);
	heap_type* right = heap_right(x.root, node);
	heap_type* largest;
	if (left - x.root < x.size && *node < *left) {
		largest = left;
	} else {
		largest = node;
	}
	if (right - x.root < x.size && *node < *right) {
		largest = right;
	}
	if (largest != node) {
		heap_type buf = *node;
		*node = *largest;
		*largest = buf;
		max_heapify(x, largest);
	}

}
