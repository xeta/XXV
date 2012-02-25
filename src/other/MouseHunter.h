/* Есть N картонных коробок, стоящих вплотную друг к другу в один ряд. В одной из них сидела мышь и прогрызла себе ходы из каждой коробки в соседние. Из крайних коробок прохода наружу она не прогрызла.
 Охотнику дали ружье и неограниченное количество патронов, чтобы убить мышь при следующих условиях
 1) изначально охотник не знает, в какой коробке сидит мышь.
 2) если охотник выстрелил в коробку, где сидит мышь, то мышь считается убитой
 3) если охотник выстрелил в коробку, где нет мыши, то после выстрела мышь обязательно переходит в любую коробку соседнюю к той, в которой она сидела в момент выстрела. И сидит там пока не грянет следующий выстрел.
 */

#ifndef MOUSEHUNTER_H_
#define MOUSEHUNTER_H_

#include "../general.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

namespace algorithm {
// Чем убивают крысу
typedef void(*__shootgun)(const void* pt);

class MouseHunter {
public:
	MouseHunter(void* start, void* end, size_t size, __shootgun shootgun,
			__is_true is_true, __printer printer);
	virtual ~MouseHunter();
	void hunt();
private:
	size_t size;
	char delta;
	char* start;
	char* end;
	__shootgun shootgun;
	__is_true is_true;
	__printer printer;
	void move_mouse();
	void printStep();
};

}
#endif
