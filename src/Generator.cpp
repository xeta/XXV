#include "Generator.h"

using namespace std;

Generator::Generator(int n) {
	this->n = n;
}

Generator::~Generator() {
}
int Generator::next_int() {
	return rand() % this->n;
}

vector<int> Generator::generateVector(int length) {
	vector<int> v(length);
	vector<int>::iterator it = v.begin();

	while (it != v.end()) {
		(*it) = next_int();
		it++;
	}
	return v;
}
