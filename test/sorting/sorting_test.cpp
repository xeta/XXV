#include "../test_helper.h"
#include "../../src/sorting/sorting.h"

const int SIZE = 10000;
void test_sort(__sorter sorter, void * const start, void * const end,
		size_t size, __comporator cmp) {
	Benchmark b = Benchmark();
	b.start();
	(sorter)(start, end, size, cmp);
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorted(start, end,size,cmp));
}

TEST(Sorting, HeapSort) {
	int* array = craeteInverseArray(SIZE);
	test_sort(heap_sort, array, array + SIZE, _INT, intComporator);
	free(array);
}

TEST(Sorting, InsertionSort) {
	int* array = craeteInverseArray(SIZE);
	test_sort(insertionSort, array, array + SIZE, _INT, intComporator);
	free(array);
}

TEST(Sorting, VoidMergeSort) {
	int* array = craeteInverseArray(SIZE);
	test_sort(mergeSort, array, array + SIZE, _INT, intComporator);
	free(array);
}

