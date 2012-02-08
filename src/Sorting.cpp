#include "Sorting.h"

void insertion_sort(int *arr, int length) {
	int buf;
	for (int i = 1; i < length; i++) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j + 1] < arr[j]) {
				buf = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buf;
			} else {
				break;
			}
		}
	}
}

