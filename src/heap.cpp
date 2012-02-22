#include "heap.h"
#include <iostream>
#include "./sorting/sorting.h"

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)						      \
  do									      \
    {									      \
      register size_t __size = (size);					      \
      register char *__a = (a), *__b = (b);				      \
      do								      \
	{								      \
	  char __tmp = *__a;						      \
	  *__a++ = *__b;						      \
	  *__b++ = __tmp;						      \
	} while (--__size > 0);						      \
    } while (0)

void* heap_parent(const void* root, const void* node, const size_t size) {
	size_t dif = ((char*) node - (char*) root - size) >> 0x01;
	return ((char*) root) + dif - dif % size;
}

void* heap_left(const void* root, const void* node, const size_t size) {
	return ((char*) root) + (((char*) node - (char*) root) << 0x01) + size;
}

void* heap_right(const void* root, const void* node, size_t size) {
	return (char*) root + (((char*) node - (char*) root + size) << 0x01);
}

void max_heapify(const void* root, const void* node, const void* end,
		const size_t size, __compar_fn_t cmp) {
	register void* _left = heap_left(root, node, size);
	register void* _right = heap_right(root, node, size);
	register char* _largest;

	if (_left < end && (cmp)(node, _left)) {
		_largest = (char*)_left;
	} else {
		_largest = (char*)node;
	}
	if (_right < end && (cmp)(_largest, _right)) {
		_largest = (char*)_right;
	}
	if (_largest != node) {
		SWAP(_largest, (char*)node, size);
		max_heapify(root, _largest, end, size, cmp);
	}
}

inline void max_heapify(const void* root, const void* node, const size_t size,
		size_t total, __compar_fn_t cmp) {
	char* _root = (char*) root;
	max_heapify(root, node, _root + size * total, size, cmp);
}

void build_heap(const void* root, size_t size, size_t total,
		__compar_fn_t cmp) {
	char* _root = (char*) root;
	char* _mid = (char*) heap_parent(_root, _root + size * total, size);
	while (_mid >= _root) {
		max_heapify(_root, _mid, size, total, cmp);
		_mid -= size;
	}
}
