#ifndef TEST_HELPER_H_
#define TEST_HELPER_H_
#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include "../src/general.h"
#include "benchmark.h"

using namespace std;

// Размер типа данных int
#define _INT sizeof(int)

// если массив отсортирован возвращает true
bool isSorted(const void* begin, const void* end, size_t size,
		__comporator cmp);

// если массив отсортирован возвращает true.
bool isSorted(const int* begin, const int* end);

// Структура данных для тестирования алгоритмов
struct TestData {
	unsigned long points;
	int age;
};

// Класс для создания массива чисел
template <typename T>
class ReverceGenerator {
public:
	ReverceGenerator(T start) :
			current(start) {
	}
	T operator()() {
		return current--;
	}
private:
	T current;
};

class RandomGenerator {
public:
	RandomGenerator(int max) :
			max(max) {
		srand((unsigned) time(NULL));
	}
	int operator()() {
		return rand() % this->max--;
	}
private:
	int max;
};

int* craeteInverseArray(size_t total);

int* craeteRandomArray(size_t total);


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

void int_printer(const void* _pt);

void print(const void* arr, size_t size, size_t total,
		void(*printer)(const void* _pt));

void print(const int* arr, size_t total);

void EXPECT_ARRAY(const void* expected, const void* actual, size_t size,
		size_t total);

int intComporator(__const void* x, __const void* y);

#endif /* TEST_HELPER_H_ */
