#include <gtest/gtest.h>
#include "test_helper.h"
#include "../heap.h"

const int SIZE = 10;

TEST(Heap,Left) {
	int xxx[] = { 1, 2, 3 };
	EXPECT_EQ(2, *heap_left(&xxx[0],&xxx[0]));
}

TEST(Heap,Right) {
	int xxx[] = { 1, 2, 3 };
	EXPECT_EQ(3, *heap_right(&xxx[0],&xxx[0]));
}

TEST(Heap,Parent) {
	int xxx[] = { 1, 2, 3 };
	EXPECT_EQ(1, *heap_parent(&xxx[0],&xxx[1]));
	EXPECT_EQ(1, *heap_parent(&xxx[0],&xxx[2]));
}
