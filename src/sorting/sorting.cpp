#include "sorting.h"

void insertionSort(Iterator start, Iterator end) {
	Iterator j;
	Iterator i = start;
	typename Iterator::value_type buf;
	for (i = start; i <= end; ++i) {
		buf = *i;
		j = i - 1;
		while ((j >= start) && (*j > buf)) {
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = buf;
	}
}

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

void void_insertionSort(void const* start, size_t size, size_t total,
		__compar_fn_t cmp) {
	register char* i = (char*) start;
	register char* end = &i[size * total];

	register char* j;
	register char* j_pr;
	while (i < end) {
		j = i;
		j_pr = j - size;
		while (j > start && (*cmp)((void *) j, (void *) (j_pr))) {
			SWAP(j_pr, j, size);
			j = j_pr;
			j_pr -= size;
		}
		i += size;
	}
}

void bubbleSort(Iterator start, Iterator end) {
	Iterator j;
	int temp, flag = 1;
	while (flag) {
		flag = 0;
		for (j = start; j < (end - 1); j++) {
			if (*(j) > *(j + 1)) {
				temp = *(j);
				*(j) = *(j + 1);
				*(j + 1) = temp;
				flag = 1;
			}
		}
	}
}

void merge(Iterator start1, Iterator end1, Iterator start2, Iterator end2) {
	Collection c1(start1, end1);
	Collection c2(start2, end2);
	Iterator x1 = c1.begin();
	Iterator x2 = c2.begin();

	while (x1 < c1.end() && x2 < c2.end()) {
		if (*x1 < *x2) {
			*start1 = *x1;
			x1++;
		} else {
			*start1 = *x2;
			x2++;
		}
		start1++;
	}

	if (x1 == c1.end()) {
		copy(x2, c2.end(), start1);
	}

	if (x2 == c2.end()) {
		copy(x1, c1.end(), start1);
	}
}

void mergeSort(Iterator start, Iterator end) {
	if (start == (end - 1))
		return;
	Iterator middle = (end - start) / 2 + start;
	mergeSort(start, middle);
	mergeSort(middle, end);
	merge(start, middle, middle, end);
}

void void_merge(const void* _start, const void* _middle, const void* _end,
		const size_t size, __comporator cmp) {

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
void void_mergeSort(const void* _start, const void* _end, const size_t size,
		__comporator cmp) {

	char* start = (char*) _start;
	char* end = (char*) _end;

	if (start == end - size)
		return;

	size_t dif = (end - start) >> 0x01;
	char* middle = start + dif - (dif % size);

	void_mergeSort(start, middle, size, cmp);
	void_mergeSort(middle, end, size, cmp);
	void_merge(start, middle, end, size, cmp);
}

void void_mergeSort(const void* _root, const size_t size, const size_t total,
		__comporator cmp) {
	void_mergeSort(_root, ((char*) _root) + size * total, size, cmp);
}

void insertionMergeSort(Iterator start, Iterator end) {
	int size = end - start;
// if collection size less then 50 use insertion sort
	if (size < 50) {
		insertionSort(start, end);
	} else {
		Iterator middle = size / 2 + start;
		mergeSort(start, middle);
		mergeSort(middle, end);
		merge(start, middle, middle, end);
	}
}

void heap_sort_temp(const void* root, const size_t size,  size_t total,
		__comporator cmp) {
	size_t _total = total;
	char* _first = (char*) root;
	char* _last = _first + (total - 1) * size;

	// Create heap structure from root poiter
	build_heap(root, size, total, cmp);

	while (_total > 1) {
		SWAP(_first, _last, size);
		_total--;
		_last -= size;
		max_heapify(_first, _first, size, _total, cmp);
	}
}
void heap_sort(const void* root, const size_t size, const size_t total,
		__comporator cmp) {
	register char* _first = (char*) root;
	char* end = _first + total * size;
	register char* _last = end - size;

	// Create heap structure from root poiter
	build_heap(root, size, total, cmp);

	while (_first != _last) {
		SWAP(_first, _last, size);
		_last -= size;
		max_heapify(_first, _first, _last, size, cmp);
	}
}

