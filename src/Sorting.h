#ifndef SORTING_H_
#define SORTING_H_
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Sorting.h"
#include <vector>
#include <sys/time.h>
#include <ctime>

using namespace std;


typedef int e_type;
typedef std::vector<int> Collection;
typedef Collection::iterator Iterator;

void insertionSort(Iterator, Iterator);

void bubbleSort(Iterator, Iterator);

void mergeSort(Iterator, Iterator);

#endif /* SORTING_H_ */
