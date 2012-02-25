#include "test_helper.h"

bool isSorted(const void* begin, const void* end, size_t size,
		__comporator cmp) {
	register char* it = (char*) begin;
	register char* next = it + size;
	while (it != (char*) end - size) {
		if (!cmp(it, next))
			return false;
		it = next;
		next += size;
	}
	return true;
}

bool isSorted(const int* begin, size_t total) {
	return isSorted(begin, begin + total, _INT, intComporator);
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

int intComporator(__const void* x, __const void* y) {
	return (*(int*) x) < (*(int*) y);
}

int* craeteInverseArray(size_t total) {
	int* data = (int*) malloc(total * _INT);
	generate(data, data + total, ReverceGenerator<int>(total));
	return data;
}

/**
 * Printing helpers, just for debug.
 */
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
	cout << endl;
}

void print(const int* arr, size_t total) {
	print(arr, _INT, total, int_printer);
}

