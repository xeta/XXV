#include "HeapSort.h"

#include "../test/test_helper.h"
#include <iostream>
void HeapSort::operator()(const void* _root, size_t _total) {
	size_t _size = this->size;
	char* _first = (char*) _root;
	char* _last = _first + (_total - 1) * _size;

	// Create heap structure from root poiter
	build_heap(_root, _size, _total, this->cmp);

	while (_total > 1) {
		SWAP(_first, _last, _size);
		_total--;
		_last -= size;
		max_heapifyXXX(_first, _first, _size, _total, this->cmp);
	}
}
