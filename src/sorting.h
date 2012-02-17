#ifndef SORTING_H_
#define SORTING_H_
#include <vector>
#include <stdlib.h>

using namespace std;

typedef int e_type;
typedef std::vector<e_type> Collection;
typedef Collection::iterator Iterator;

void void_insertionSort(void const* start, size_t size, size_t total,
		__compar_d_fn_t cmp);

void insertionSort(Iterator start, Iterator end);

void bubbleSort(Iterator, Iterator);

void mergeSort(Iterator, Iterator);

void insertionMergeSort(Iterator, Iterator);

#endif /* SORTING_H_ */
