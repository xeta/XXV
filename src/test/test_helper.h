#ifndef TEST_HELPER_H_
#define TEST_HELPER_H_
#include <vector>
#include <algorithm>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

#define _INT sizeof(int)

struct TestData{
	unsigned long points;
	string name;
	int age;
};

//class TestGenerator {
//public:
//	TestGenerator(unsigned long start) :
//			current(start) {
//	}
//
//	TestData operator()() {
//		TestData data;
//		data.name = "test name";
//		data.points = current++;
//		data.age = 0;
//		return data;
//	}
//private:
//	unsigned long current;
//};

template<class T>
class BasicComporator {
public:
	int operator()(T i, T j) {
		return i > j;
	}
};

template<class T>
class Generator {
public:
	Generator(T start) :
			current(start) {
	}
	T operator()() {
		return current--;
	}
private:
	T current;
};

vector<int> createVector(size_t size);

TestData* createData(size_t size);

void int_printer(const void* _pt);

void print(const void* arr, size_t size, size_t total,
		void(*printer)(const void* _pt));

void print(const int* arr, size_t total);

void EXPECT_ARRAY(const void* expected, const void* actual, size_t size,
		size_t total);

int int_comporator(const void* x, const void* y);

#endif /* TEST_HELPER_H_ */
