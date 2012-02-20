#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "sorting.h"
#include "../heap.h"

using namespace std;
typedef int (*__comporator) (__const void *, __const void *);

class HeapSort {
public:
	HeapSort(const size_t size, __comporator cmp) {
		this->size = size;
		this->cmp = cmp;
	};
	void operator()(const void* start, size_t total);
private:
	size_t size;
	__comporator cmp;
};

#endif /* HEAPSORT_H_ */
