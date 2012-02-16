#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "sorting.h"
#include <vector>
#include <list>
#include <sys/time.h>
#include <ctime>

using namespace std;

class Generator {
public:
	Generator(int);
	virtual ~Generator();
	vector<int> generateVector(int);
private:
	int n;
	int next_int();
};

#endif /* GENERATOR_H_ */
