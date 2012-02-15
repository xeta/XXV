#include "sorting.h"

void insertionSort(Iterator start, Iterator end) {
	Iterator j;
	Iterator i = start;
	e_type buf = 0;

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