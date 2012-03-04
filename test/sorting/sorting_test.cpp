#include "../test_helper.h"
#include "../../src/sorting/sorting.h"

Benchmark BM = Benchmark();
const int _1000 = 1000;
const int _10000 = 10000;
const int _100000 = 100000;
const int _1000000 = 1000000;
const int _64000000 = 64000000;

void test_sorter(__sorter sorter, void * const start, void * const end,
		size_t size, __comporator cmp) {
	BM.start();
	(sorter)(start, end, size, cmp);
	cout << BM.getTime() << "\t";
	EXPECT_TRUE(isSorted(start, end,size,cmp));
}

void reverse_test_int_sorter(size_t size, __sorter sorter) {
	int* array = craeteInverseArray(size);
	test_sorter(sorter, array, array + size, _INT, intComporator);
	free(array);
}

void reverse_test_int_sorter(string name, __sorter sorter) {
	cout << "[ NAME     ] " << name << endl;
	cout << "[ TIME     ] ";

	reverse_test_int_sorter(_1000, sorter);
	reverse_test_int_sorter(_10000, sorter);
	reverse_test_int_sorter(_100000, sorter);
	cout << endl;
}

void random_test_int_sorter(size_t size, __sorter sorter) {
	int* array = craeteRandomArray(size);
	test_sorter(sorter, array, array + size, _INT, intComporator);
	free(array);
}

void random_test_int_sorter(string name, __sorter sorter) {
	cout << "[ NAME     ] " << name << endl;
	cout << "[ TIME     ] ";
	random_test_int_sorter(_1000, sorter);
	random_test_int_sorter(_10000, sorter);
	random_test_int_sorter(_100000, sorter);
	cout << endl;
}

TEST(Sorting, InverseOrderSort) {
	cout << "[ TIME     ] " << "1000    \t10000   \t100000" << endl;
	reverse_test_int_sorter("heapSort", heapSort);
	reverse_test_int_sorter("mergeSort", mergeSort);
	reverse_test_int_sorter("qgit uickSort", quickSort);
//	reverse_test_int_sorter("insertionSort", insertionSort);
}

TEST(Sorting, RandomOrderSort) {
	cout << "[ TIME     ] " << "1000    \t10000   \t100000" << endl;
	random_test_int_sorter("heapSort", heapSort);
	random_test_int_sorter("mergeSort", mergeSort);
	random_test_int_sorter("quickSort", quickSort);
//	random_test_int_sorter("insertionSort", insertionSort);
}

TEST(Sorting, CountSort) {
	int size = _1000;
	int* array = craeteRandomArray(size);
	BM.start();
	countSort(array, size, size);
	cout << "[ TIME     ] 100000 => " << BM.getTime() << endl;
	EXPECT_TRUE(isSorted(array, size));
	free(array);
}

