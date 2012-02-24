#include "test_helper.h"
#include "../other/MouseHunter.h"

using namespace algorithm;
bool is_true(const void* pt) {
	return *((int*) pt) == 1;
}

void shootgun(const void* pt) {
	*((int*) pt) = 0;
}

TEST(MouseHunter, test) {
	size_t total = 10;
	int* start = (int*) malloc(_INT * total);
	int* end = (int*) start + total;
	fill(start, end, 1);
	MouseHunter xxx(start, end, _INT, shootgun, is_true, int_printer);
	xxx.hunt();
}
