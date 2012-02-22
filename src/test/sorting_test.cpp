#include <limits.h>
#include <gtest/gtest.h>
#include "test_helper.h"
#include "../sorting/sorting.h"

#include "../benchmark.h"

template<class Comp>
bool isSorting(Iterator begin, Iterator end, Comp comparator) {
	while (begin < end - 1) {
		if ((comparator)(*begin, *(begin + 1)))
			return false;
		begin++;
	}
	return true;
}

bool isSorting(Iterator begin, Iterator end) {
	return isSorting(begin, end, BasicComporator<int>());
}

const unsigned int SIZE = 1000;

TEST(Sorting, InsertionSort) {
	vector<int> x = createVector(SIZE);
	Benchmark b = Benchmark();
	b.start();
	insertionSort(x.begin(), x.end());
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorting(x.begin(), x.end()));
}

TEST(Sorting, BubleSort) {
	vector<int> x = createVector(SIZE);
	Benchmark b = Benchmark();
	b.start();
	bubbleSort(x.begin(), x.end());
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorting(x.begin(), x.end()));
}

TEST(Sorting, MergeSort) {
	vector<int> x = createVector(SIZE);
	Benchmark b = Benchmark();
	b.start();
	mergeSort(x.begin(), x.end());
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorting(x.begin(), x.end()));
}

TEST(Sorting, InsertiobMergeSort) {
	vector<int> x = createVector(SIZE);
	Benchmark b = Benchmark();
	b.start();
	insertionMergeSort(x.begin(), x.end());
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorting(x.begin(), x.end()));
}

TEST(Sorting, VoidInsertionSort) {
	int x[SIZE];
	generate(&x[0], &x[SIZE - 1], Generator<int>(SIZE));
	Benchmark b = Benchmark();
	b.start();
	void_insertionSort(&x[0], sizeof(int), SIZE, int_comporator);
	cout << "[ TIME     ] " << b.getTime() << endl;
	vector<int> a(&x[0], &x[SIZE - 1]);
	EXPECT_TRUE(isSorting(a.begin(),a.end()));
}

TEST(Sorting, Sort) {
	vector<int> x = createVector(SIZE);
	Benchmark b = Benchmark();
	b.start();
	sort(x.begin(), x.end());
	cout << "[ TIME     ] " << b.getTime() << endl;
	EXPECT_TRUE(isSorting(x.begin(), x.end()));
}

TEST(Sorting, VoidMergeSort) {
	int x[SIZE];
	generate(&x[0], &x[SIZE], Generator<int>(SIZE));
	Benchmark b = Benchmark();
	b.start();
	void_mergeSort(&x[0], sizeof(int), SIZE, int_comporator);
	cout << "[ TIME     ] " << b.getTime() << endl;
	vector<int> a(&x[0], &x[SIZE]);
	EXPECT_TRUE(isSorting(a.begin(),a.end()));
}

TEST(Sorting, HeapSort) {
	int x[SIZE];
	generate(&x[0], &x[SIZE], Generator<int>(SIZE));
	HeapSort xx(_INT, int_comporator);
	Benchmark b = Benchmark();
	b.start();
	(xx)(x, SIZE);
	cout << "[ TIME     ] " << b.getTime() << endl;
	vector<int> a(&x[0], &x[SIZE]);
	EXPECT_TRUE(isSorting(a.begin(),a.end()));
}
