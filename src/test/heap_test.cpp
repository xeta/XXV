#include "test_helper.h"
#include "../heap.h"

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



TEST(Heap,Right) {
	int size = 10;
	int int_array[size];
	test_array_to_right(int_array, _INT);

	char char_array[size];
	test_array_to_right(char_array, _INT);

	TestData struct_array[size];
	test_array_to_right(struct_array, sizeof(TestData));
}

TEST(Heap, MaxHepify_1) {
	int actual[] = { 2, 1, 3 };
	int expected[] = { 3, 1, 2 };
	max_heapifyXXX(actual, actual, _INT, 3, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, 3);
}

TEST(HEAP, MaxHepify_2) {
	int actual[] = { 0, 4, 3, 2, 1 };
	int expected[] = { 4, 2, 3, 0, 1 };
	max_heapifyXXX(actual, actual, _INT, 5, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, 5);
}

TEST(HEAP, MaxHepify_3) {
	int actual[] = { 4, 0, 3, 1, 2 };
	int expected[] = { 4, 2, 3, 1, 0 };
	max_heapifyXXX(actual, &actual[1], _INT, 5, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, 5);
}

TEST(Heap, BuildHeap_1) {
	size_t size = 3;
	int actual[] = { 1, 6, 0 };
	int expected[] = { 6, 1, 0 };
	build_heap(actual, _INT, size, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

TEST(Heap, BuildHeap_2) {
	int size = 5;
	int actual[] = { 1, 6, 0, 2, 7 };
	int expected[] = { 7, 6, 0, 2, 1 };
	build_heap(actual, _INT, size, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

TEST(Heap, BuildHeap_3) {
	int size = 10;
	int actual[] = { 1, 6, 0, 2, 7, 9, 4, 8, 3, 5 };
	int expected[] = { 9, 8, 4, 6, 7, 0, 1, 2, 3, 5 };
	build_heap(actual, _INT, size, int_comporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

