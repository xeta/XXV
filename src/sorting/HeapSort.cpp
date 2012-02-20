#include "HeapSort.h"

#include "../test/test_helper.h"
#include <iostream>
void HeapSort::operator()(const void* _root, size_t _total) {
	size_t _size = this->size;
	register char* _first = (char*) _root;
	register char* _last = (char*) _root + (_total - 1) * _size;

	// Create heap structure from root poiter
	build_heap(_root, _size, _total, this->cmp);

	while (_total > 1) {
		SWAP(_first, _last, _size);
		_total--;
		_last -= size;
		max_heapify(_first, _first, _size, _total, this->cmp);
	}
}
