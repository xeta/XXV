#ifndef SORTING_H_
#define SORTING_H_
#include <vector>
#include <stdlib.h>
#include "HeapSort.h"

using namespace std;

typedef int e_type;
typedef std::vector<e_type> Collection;
typedef Collection::iterator Iterator;


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


typedef int (*__comporator) (__const void *, __const void *);

void void_insertionSort(void const* start, size_t size, size_t total,
		__compar_fn_t cmp);

void insertionSort(Iterator start, Iterator end);

void bubbleSort(Iterator, Iterator);

void mergeSort(Iterator, Iterator);

void insertionMergeSort(Iterator, Iterator);

#endif /* SORTING_H_ */
