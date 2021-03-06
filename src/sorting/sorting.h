#ifndef SORTING_H_
#define SORTING_H_
#include "../general.h"
#include "heap.h"
#include <stdlib.h>
#include <string.h>
#include <stack>
typedef struct {
	char* begin;
	char* end;
} part_t;

// Прототип для функций сортировки
typedef void(*__sorter)(void * const _start, void * const _end, size_t size,
		__comporator cmp);

void insertionSort(void * const _start, void * const _end, size_t size,
		__comporator cmp);
void mergeSort(void * const _start, void* const _end, size_t size,
		__comporator cmp);
void heapSort(void * const root, void * const end, size_t size,
		__comporator cmp);
void quickSort(void * const root, void * const end, size_t size,
		__comporator cmp);


void countSort(int* array, size_t length, size_t num_values);
#endif /* SORTING_H_ */
