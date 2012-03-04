#include "HanoiTower.h"
namespace algorithm {

HanoiTower::HanoiTower(size_t size) {
	this->first_tower = (tower*) malloc(sizeof(tower));
	this->first_tower->data = (int*) calloc(size * _INT, _INT);
	this->first_tower->count = size;
	this->second_tower = (tower*) malloc(sizeof(tower));
	this->second_tower->data = (int*) calloc(size * _INT, _INT);
	this->second_tower->count = 0;
	this->third_tower = (tower*) malloc(sizeof(tower));
	this->third_tower->data = (int*) calloc(size * _INT, _INT);
	this->third_tower->count = 0;
	this->step = 0;
	generate(this->first_tower->data, this->first_tower->data + size,
			TowerGenerator(size));
	printState();
	next_step(this->first_tower, this->second_tower, this->third_tower, size);

}

HanoiTower::~HanoiTower() {
	free(this->first_tower);
	free(this->second_tower);
	free(this->third_tower);
}
void HanoiTower::next_step(tower* first_tower, tower* second_tower,
		tower* third_tower, size_t size) {
	if (size == 1) {
		move(first_tower, third_tower);
		return;
	}
	next_step(first_tower, third_tower, second_tower, size - 1);
	move(first_tower, third_tower);
	next_step(second_tower, first_tower, third_tower, size - 1);
}

void HanoiTower::printTower(tower* t) {
	int* iterator = t->data;
	while (iterator != t->data + t->count) {
		cout << *iterator << " ";
		iterator++;
	}
	cout << endl;
}

void HanoiTower::printState() {
	cout << "---- STEP "<< this->step <<" ----" << endl;
	printTower(this->first_tower);
	printTower(this->second_tower);
	printTower(this->third_tower);
}


void HanoiTower::move(tower* from, tower* to) {
	from->count--;
	*(to->data + to->count) = *(from->data + from->count);
//	*(from.data + from.count) = 0;
	to->count++;
	this->step++;
	printState();
}
}

