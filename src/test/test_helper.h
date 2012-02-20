#ifndef TEST_HELPER_H_
#define TEST_HELPER_H_
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TestData{
	unsigned long points;
	string name;
	int age;
};

template<class T>
class BasicComporator {
public:
	int operator()(T i, T j) {
		return i > j;
	}
};

template<class T>
class Generator {
public:
	Generator(T start) :
			current(start) {
	}
	T operator()() {
		return current--;
	}
private:
	T current;
};

vector<int> createVector(size_t size);

TestData* createData(size_t size);

#endif /* TEST_HELPER_H_ */
