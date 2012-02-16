#include <limits.h>
#include <algorithm>
#include <gtest/gtest.h>
#include "../sorting.h"
#include "../benchmark.h"

template<class T>
class IncrementGenerator {
public:
	IncrementGenerator(T start) :
			current(start) {
	}
	T operator()() {
		return current++;
	}
private:
	T current;
};

template<class T>
class DecrementGenerator {
public:
	DecrementGenerator(T start) :
			current(start) {
	}
	T operator()() {
		return current--;
	}
private:
	T current;
};

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

vector<int> createVector(int size) {
	vector<int> vect(size);
	generate(vect.begin(), vect.end(), DecrementGenerator<int>(size));
	return vect;
}

const int SIZE = 500;

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
