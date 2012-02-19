#include <gtest/gtest.h>
#include "test_helper.h"
#include "../heap.h"
//#include <algorithm>

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
	EXPECT_EQ(3,xxx[0]);
	EXPECT_EQ(1,xxx[1]);
	EXPECT_EQ(2,xxx[2]);

	int aaa[] = { 0, 4, 3 , 2, 1};
	max_heapify(&aaa[0], &aaa[0], sizeof(int), 5, cmp);
	EXPECT_EQ(4,aaa[0]);
	EXPECT_EQ(2,aaa[1]);
	EXPECT_EQ(3,aaa[2]);
	EXPECT_EQ(0,aaa[3]);
	EXPECT_EQ(1,aaa[4]);

	int aaa1[] = { 4, 0, 3 , 1, 2};
	max_heapify(&aaa1[0], &aaa1[1], sizeof(int), 5, cmp);
	EXPECT_EQ(4,aaa1[0]);
	EXPECT_EQ(2,aaa1[1]);
	EXPECT_EQ(3,aaa1[2]);
	EXPECT_EQ(1,aaa1[3]);
	EXPECT_EQ(0,aaa1[4]);
}

