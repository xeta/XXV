#include "sorting.h"

void heapSort(void * const root, void * const end, size_t size,
		__comporator cmp) {
	register char* _first = (char*) root;
	register char* _last = (char*) end - size;

	// Create heap structure from root pointer
	build_heap(root, end, size, cmp);

	while (_first != _last) {
		SWAP(_first, _last, size);
		_last -= size;
		max_heapify(_first, _first, _last + size, size, cmp);
	}
}

//TODO this function need to be rewritten
void insertionSort(void * const _start, void * const _end, size_t size,
		__comporator cmp) {
	register char* iterator = (char*) _start;
	register char* end = (char*) _end;

	register char* j;
	register char* j_pr;
	while (iterator < end) {
		j = iterator;
		j_pr = j - size;
		while (j > _start && (*cmp)((void *) j, (void *) (j_pr))) {
			SWAP(j_pr, j, size);
			j = j_pr;
			j_pr -= size;
		}
		iterator += size;
	}
}

void merge(const void* _start, const void* _middle, const void* _end,
		size_t size, __comporator cmp) {

	register char* iterator = (char*) _start;
	size_t left_size = (char*) _middle - iterator;
	size_t right_size = (char*) _end - (char*) _middle;

	register char* left_buffer = (char*) malloc(left_size);
	memcpy(left_buffer, iterator, left_size);
	char* left_buffer_end = left_buffer + left_size;

	register char* right_buffer = (char*) malloc(right_size);
	memcpy(right_buffer, (char*) _start + left_size, right_size);
	char* right_buffer_end = right_buffer + right_size;

	while (left_buffer < left_buffer_end && right_buffer < right_buffer_end) {
		if ((cmp)(left_buffer, right_buffer)) {
			memcpy(iterator, left_buffer, size);
			left_buffer += size;
		} else {
			memcpy(iterator, right_buffer, size);
			right_buffer += size;
		}
		iterator += size;
	}
	if (left_buffer == left_buffer_end) {
		memcpy(iterator, right_buffer, (right_buffer_end - right_buffer));
	}
	if (right_buffer == right_buffer_end) {
		memcpy(iterator, left_buffer, (left_buffer_end - left_buffer));
	}

}
void mergeSort(void * const _start, void* const _end, size_t size,
		__comporator cmp) {
	char* start = (char*) _start;
	char* end = (char*) _end;

	if (start == end - size)
		return;

	size_t dif = (end - start) >> 0x01;
	char* middle = start + dif - (dif % size);

	mergeSort(start, middle, size, cmp);
	mergeSort(middle, end, size, cmp);
	merge(start, middle, end, size, cmp);
}

