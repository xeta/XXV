#ifndef SORTING_H_
#define SORTING_H_
#include <vector>

using namespace std;

typedef int e_type;
typedef std::vector<e_type> Collection;
typedef Collection::iterator Iterator;

void insertionSort(Iterator, Iterator);

void bubbleSort(Iterator, Iterator);

void mergeSort(Iterator, Iterator);

void insertionMergeSort(Iterator, Iterator);

#endif /* SORTING_H_ */
