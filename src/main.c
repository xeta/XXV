#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


void print(int arr[], int length){
	printf("[");
	for(int i=0; i<length; i++){
		if(i!=0){
			printf(", ");
		}
		printf("%d",arr[i]);
	}
	printf("]\n");
}


int main(int argc, char **argv) {
//	int* pInt;
//	pInt = (int*) malloc(10*sizeof(int));
//	for (int var = 0; var < sizeof(&pInt); var++) {
//		*pInt = var;
//
//		printf("%d %d\n",*pInt, var);
//		pInt++;
//	}

	int testData[] = {10,9,8,7,6,5,4,3,2,1};
	int length = sizeof(testData)/sizeof(testData[0]);
	print(testData, length);
	insertion_sort(testData, length);
	print(testData, length);

	return 0;
}
