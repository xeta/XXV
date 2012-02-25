#include "heap.h"

void* heap_parent(void * const root, const void* node, size_t size) {
	size_t dif = ((char*) node - (char*) root - size) >> 0x01;
	return ((char*) root) + dif - dif % size;
}

void* heap_right(void * const root, size_t offset, size_t size) {
	return (char*) root + offset + (size << 0x01);
}
void* heap_left(void * const root, size_t offset, const size_t size) {
	return ((char*) root) + offset + size;
}

void max_heapify(void * const root, void * const node, void * const end,
		size_t size, __comporator cmp) {
	register size_t offset = ((char*) node - (char*) root) << 0x01;
	register void* _left = heap_left(root, offset, size);
	register void* _right = heap_right(root, offset, size);
	register void* _largest;

	if (_left < end && (cmp)(node, _left)) {
		_largest = _left;
	} else {
		_largest = (char*) node;
	}
	if (_right < end && (cmp)(_largest, _right)) {
		_largest = _right;
	}
	if (_largest != node) {
		SWAP((char*)_largest, (char*)node, size);
		max_heapify(root, _largest, end, size, cmp);
	}
}

void build_heap(void * const root, void * const end, size_t size,
		__comporator cmp) {
	char* _root = (char*) root;
	char* _mid = (char*) heap_parent(_root, end, size);
	while (_mid >= _root) {
		max_heapify(_root, _mid, end, size, cmp);
		_mid -= size;
	}

}
