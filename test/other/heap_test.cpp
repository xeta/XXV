#include "../test_helper.h"
#include "../../src/sorting/heap.h"

TEST(Heap, MaxHepify) {
	int actual[] = { 2, 1, 3 };
	int expected[] = { 3, 1, 2 };
	max_heapify(actual, actual, actual + 3, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, 3);
}

TEST(HEAP, MaxHepify_2) {
	int actual[] = { 0, 4, 3, 2, 1 };
	int expected[] = { 4, 2, 3, 0, 1 };
	max_heapify(actual, actual, actual + 5, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, 5);
}

TEST(HEAP, MaxHepify_3) {
	int actual[] = { 4, 0, 3, 1, 2 };
	int expected[] = { 4, 2, 3, 1, 0 };
	max_heapify(actual, &actual[1], actual + 5, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, 5);
}

TEST(Heap, BuildHeap_1) {
	size_t size = 3;
	int actual[] = { 1, 6, 0 };
	int expected[] = { 6, 1, 0 };
	build_heap(actual, actual + size, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

TEST(Heap, BuildHeap_2) {
	int size = 5;
	int actual[] = { 1, 6, 0, 2, 7 };
	int expected[] = { 7, 6, 0, 2, 1 };
	build_heap(actual, actual + size, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

TEST(Heap, BuildHeap_3) {
	int size = 10;
	int actual[] = { 1, 6, 0, 2, 7, 9, 4, 8, 3, 5 };
	int expected[] = { 9, 8, 4, 6, 7, 0, 1, 2, 3, 5 };
	build_heap(actual, actual + size, _INT, intComporator);
	EXPECT_ARRAY(expected, actual, _INT, size);
}

