#include "test_helper.h"


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

int int_comporator(__const void* x, __const void* y) {
	return (*(int*) x) < (*(int*) y);
}

vector<int> createVector(size_t size) {
	vector<int> vect(size);
	generate(vect.begin(), vect.end(), Generator<int>(size));
	return vect;
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

