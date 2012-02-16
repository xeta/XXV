#ifndef TEST_HELPER_H_
#define TEST_HELPER_H_
#include <vector>
#include <algorithm>

using namespace std;

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

vector<int> createVector(int size);

#endif /* TEST_HELPER_H_ */
