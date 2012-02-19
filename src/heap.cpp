#include "heap.h"
#include <iostream>
#include "sorting.h"

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

void* heap_left(const void* root, void* node, const size_t size) {
	return ((char*) root) + (((char*) node - (char*) root) << 0x01) + size;
}

void* heap_right(const void* root, void* node, size_t size) {
	return (char*) root + (((char*) node - (char*) root + size) << 0x01);
}

void max_heapify(const void* root, void* node, const size_t size, size_t total,
		__compar_fn_t cmp) {
	register char* _root = (char*) root;
	register char* _left = (char*) heap_left(root, node, size);
	register char* _right = (char*) heap_right(root, node, size);
	register char* _largest;

	if ((_left - _root) / size < total && (cmp)(node, _left)) {
		_largest = _left;
	} else {
		_largest = (char*) node;
	}
	if ((_right - _root) / size < total && (cmp)(_largest, _right)) {
		_largest = _right;
	}
	if (_largest != node) {
		SWAP(_largest, (char*)node, size);
		max_heapify(root, _largest, size, total, cmp);
	}
}

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
