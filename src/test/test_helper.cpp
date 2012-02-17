#include "test_helper.h"

vector<int> createVector(int size) {
	vector<int> vect(size);
	generate(vect.begin(), vect.end(), Generator<int>(size));
	return vect;
}

