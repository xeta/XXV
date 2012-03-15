#ifndef HANOITOWER_H_
#define HANOITOWER_H_

#include <stddef.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "../general.h"

using namespace std;

namespace algorithm {

struct tower{
	int* data;
	int count;
};

class TowerGenerator {
public:
	TowerGenerator(size_t size) {
		this->counter = size;
	}
	size_t operator()() {
		return counter--;
	}
private:
	size_t counter;
};

class HanoiTower {
public:
	HanoiTower(size_t size);
	virtual ~HanoiTower();
private:
	void next_step(tower* first_tower, tower* second_tower, tower* third_tower, size_t size);
	void move(tower* from, tower* to);
	void printTower(tower* t);
	void printState();
	tower* first_tower;
	tower* second_tower;
	tower* third_tower;
	size_t step;
};
}
#endif
