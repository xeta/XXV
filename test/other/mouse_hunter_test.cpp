#include "../test_helper.h"
#include "../../src/other/MouseHunter.h"

using namespace algorithm;
bool is_true(const void* pt) {
	return *((int*) pt) == 1;
}

void shootgun(const void* pt) {
	*((int*) pt) = 0;
}

// Данный тест ничего не проверяет. Просто зпускает задачу с мышкой и коробками
TEST(MouseHunter, test) {
	size_t total = 6;
	int* start = (int*) malloc(_INT * total);
	int* end = (int*) start + total;
	fill(start, end, 1);
	MouseHunter hunter(start, end, _INT, shootgun, is_true, int_printer);
	hunter.hunt();
}
