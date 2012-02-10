#include "Sorting.h"

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

void bubbleSort(Iterator start, Iterator end){
	Iterator j;
	int temp, flag = 1;
	while(flag){
		flag = 0;
		for(j=start;j<(end-1);j++){
			if(*(j) > *(j+1)){
				temp = *(j);
				*(j) = *(j+1);
				*(j+1) = temp;
				flag = 1;
			}
		}
	}
}

void mergeSort(Iterator start, Iterator end){
// TODO Merge sort
}

