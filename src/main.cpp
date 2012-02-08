#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"


void printArr(int *arr, int length){
	printf("[");
	for(int i=0; i<length; i++){
		if(i!=0){
			printf(", ");
		}
		printf("%d", arr[i]);
	}
	printf("]\n");
}

int main(int argc, char **argv) {
	int testData[] = {10,9,8,7,6,5,4,3,2,1};
	int length = sizeof(testData)/sizeof(testData[0]);

	printArr(testData, length);
	insertion_sort(testData, length);
	printArr(testData, length);

	return 0;
}
