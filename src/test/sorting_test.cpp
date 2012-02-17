#include <limits.h>
#include <gtest/gtest.h>
#include "test_helper.h"
#include "../sorting.h"
#include "../benchmark.h"



template<class T>
class BasicComporator {
public:
	bool operator()(T i, T j) {
		return i > j;
	}
};

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
