#include "test_helper.h"

vector<int> createVector(size_t size) {
	vector<int> vect(size);
	generate(vect.begin(), vect.end(), Generator<int>(size));
	return vect;
}
