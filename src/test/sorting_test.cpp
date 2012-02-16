#include <limits.h>
#include "../sorting.h"
#include "gtest/gtest.h"

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
class BasicComporator {
public:
	bool operator()(T i, T j) {
		return i < j;
	}
};

TEST(InsertionSort, IntegerSort) {
	int size = 3;
	Collection x(size);
	generate(x.begin(), x.end(), IncrementGenerator<int>(0));
	insertionSort(x.begin(), x.end());
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
	EXPECT_EQ(2, x[2]);
}

TEST(STLSort, IntegerSort) {
	int size = 3;
	Collection x(size);
	generate(x.begin(), x.end(), IncrementGenerator<int>(0));
	sort(x.begin(), x.end(), BasicComporator<int>());
	EXPECT_EQ(0, x[0]);
	EXPECT_EQ(1, x[1]);
	EXPECT_EQ(2, x[2]);
}

