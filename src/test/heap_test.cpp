#include <gtest/gtest.h>
#include "test_helper.h"
#include "../heap.h"

class TestGenerator {
public:
	TestGenerator(unsigned long start) :
			current(start) {
	}

	TestData operator()() {
		TestData data;
		data.name = "test name";
		data.points = current++;
		data.age = 0;
		return data;
	}
private:
	unsigned long current;
};

void test_array_to_parent(void* arr, size_t size) {
	char* test_array = (char*) arr;
	EXPECT_EQ(&test_array[0],
			heap_parent(&test_array[0], &test_array[1*size], size));
	EXPECT_EQ(&test_array[0],
			heap_parent(&test_array[0], &test_array[2*size], size));
	EXPECT_EQ(&test_array[1*size],
			heap_parent(&test_array[0], &test_array[3*size], size));
	EXPECT_EQ(&test_array[1*size],
			heap_parent(&test_array[0], &test_array[4*size], size));
	EXPECT_EQ(&test_array[2*size],
			heap_parent(&test_array[0], &test_array[5*size], size));
	EXPECT_EQ(&test_array[2*size],
			heap_parent(&test_array[0], &test_array[6*size], size));
	EXPECT_EQ(&test_array[3*size],
			heap_parent(&test_array[0], &test_array[7*size], size));
	EXPECT_EQ(&test_array[3*size],
			heap_parent(&test_array[0], &test_array[8*size], size));
	EXPECT_EQ(&test_array[4*size],
			heap_parent(&test_array[0], &test_array[9*size], size));
}

void test_array_to_left(void* arr, size_t size) {
	char* test_array = (char*) arr;
	EXPECT_EQ(&test_array[1*size],
			heap_left(&test_array[0], &test_array[0*size], size));
	EXPECT_EQ(&test_array[3*size],
			heap_left(&test_array[0], &test_array[1*size], size));
	EXPECT_EQ(&test_array[5*size],
			heap_left(&test_array[0], &test_array[2*size], size));
	EXPECT_EQ(&test_array[7*size],
			heap_left(&test_array[0], &test_array[3*size], size));
	EXPECT_EQ(&test_array[9*size],
			heap_left(&test_array[0], &test_array[4*size], size));
}

void test_array_to_right(void* arr, size_t size) {
	char* test_array = (char*) arr;
	EXPECT_EQ(&test_array[2*size],
			heap_right(&test_array[0], &test_array[0], size));
	EXPECT_EQ(&test_array[4*size],
			heap_right(&test_array[0], &test_array[1*size], size));
	EXPECT_EQ(&test_array[6*size],
			heap_right(&test_array[0], &test_array[2*size], size));
	EXPECT_EQ(&test_array[8*size],
			heap_right(&test_array[0], &test_array[3*size], size));
}

TEST(Heap, Parent) {
	int size = 10;
	int int_array[size];
	test_array_to_parent(int_array, sizeof(int));

	char char_array[size];
	test_array_to_parent(char_array, sizeof(int));

	TestData struct_array[size];
	test_array_to_parent(struct_array, sizeof(TestData));
}

TEST(Heap,Left) {
	int size = 10;
	int int_array[size];
	test_array_to_left(int_array, sizeof(int));

	char char_array[size];
	test_array_to_left(char_array, sizeof(int));

	TestData struct_array[size];
	test_array_to_left(struct_array, sizeof(TestData));
}

int cmp(const void* x, const void* y) {
	return (*(int*) x) < (*(int*) y);
}

TEST(Heap,Right) {
	int size = 10;
	int int_array[size];
	test_array_to_right(int_array, sizeof(int));

	char char_array[size];
	test_array_to_right(char_array, sizeof(int));

	TestData struct_array[size];
	test_array_to_right(struct_array, sizeof(TestData));
}
TEST(Heap, MaxHepify) {
	int xxx[] = { 2, 1, 3 };
	max_heapify(&xxx[0], &xxx[0], sizeof(int), 3, cmp);
	EXPECT_EQ(3, xxx[0]);
	EXPECT_EQ(1, xxx[1]);
	EXPECT_EQ(2, xxx[2]);

	int aaa[] = { 0, 4, 3, 2, 1 };
	max_heapify(&aaa[0], &aaa[0], sizeof(int), 5, cmp);
	EXPECT_EQ(4, aaa[0]);
	EXPECT_EQ(2, aaa[1]);
	EXPECT_EQ(3, aaa[2]);
	EXPECT_EQ(0, aaa[3]);
	EXPECT_EQ(1, aaa[4]);

	int aaa1[] = { 4, 0, 3, 1, 2 };
	max_heapify(&aaa1[0], &aaa1[1], sizeof(int), 5, cmp);
	EXPECT_EQ(4, aaa1[0]);
	EXPECT_EQ(2, aaa1[1]);
	EXPECT_EQ(3, aaa1[2]);
	EXPECT_EQ(1, aaa1[3]);
	EXPECT_EQ(0, aaa1[4]);
}
void int_printer(const void* _pt) {
	cout << *((int*) _pt) << " ";
}

void print(const void* arr, size_t size, size_t total,
		void(*printer)(const void* _pt)) {
	register char* _pt = (char*) arr;
	register char* _end = _pt + size * total;
	while (_pt != _end) {
		(printer)(_pt);
		_pt += size;
	}
}

void print(const int* arr, size_t total) {
	print(arr, sizeof(int), total, int_printer);
}

void EXPECT_ARRAY(const void* expected, const void* actual, size_t size,
		size_t total) {
	char* _expected = (char*) expected;
	char* _end = _expected + size * total;
	char* _actual = (char*) actual;
	while (_expected != _end) {
		EXPECT_EQ(*(_expected), *(_actual));
		_expected++;
		_actual++;
	}
}

TEST(Heap, BuildHeap) {
	int xxx[] = { 1, 6, 0 };
	size_t size = 3;
	print(xxx, size);
	cout << endl;
	build_heap(xxx, sizeof(int), size, cmp);
	print(xxx, size);
	cout << endl;
	int expected[] = { 6, 1, 0 };
	EXPECT_ARRAY(expected , xxx, sizeof(int), size);

	int xxx1[] = { 1, 6, 0, 2, 7 };
	size = 5;
	print(xxx1, size);
	cout << endl;
	build_heap(xxx1, sizeof(int), size, cmp);
	print(xxx1, size);
	cout << endl;
	int expected1[] = { 7, 6, 0, 2, 1 };
	EXPECT_ARRAY(expected1 , xxx1, sizeof(int), size);

	int aaa[] = { 1, 6, 0, 2, 7, 9, 4, 8, 3, 5 };
	size = 10;
	print(aaa, size);
	cout << endl;
	build_heap(aaa, sizeof(int), size, cmp);
	print(aaa, size);
	cout << endl;
	int expected2[] = { 9, 8, 4, 6, 7, 0, 1, 2, 3, 5 };
	EXPECT_ARRAY(expected2 , aaa, sizeof(int), size);
}

