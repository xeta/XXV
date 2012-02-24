#ifndef MOUSEHUNTER_H_
#define MOUSEHUNTER_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

namespace algorithm {

class MouseHunter {
public:
	MouseHunter(void* start, void* end, size_t size, void (*shootgun)(const void* pt),
			bool(*is_true)(const void* pt), void(*printer)(const void* pt)) {
		this->start = (char*) start;
		this->end = (char*) end;
		this->size = size;
		this->delta = 1;
		this->shootgun=shootgun;
		this->is_true = is_true;
		this->printer = printer;
	}
	;
	virtual ~MouseHunter();
	void hunt();
private:
	size_t size;
	char delta;
	char* start;
	char* end;
	void(*shootgun)(const void* pt);
	bool (*is_true)(const void* pt);
	void (*printer)(const void* pt);
	void move_mouse();
	void printStep();
};

}
#endif
