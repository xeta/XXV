#include "MouseHunter.h"

namespace algorithm {

MouseHunter::~MouseHunter() {
}

void MouseHunter::printStep() {
	register char* iterator = this->start;
	while (iterator != this->end) {
		this->printer(iterator);
		cout << " ";
		iterator += this->size;
	}
	cout << endl;

}

void MouseHunter::hunt() {
	register char* iterator = this->start + this->size;
	register char* last_shooted = this->end - (this->size << 0x01);
	while (iterator != this->start) {
		printStep();
		cout << "shoot " << ((iterator - this->start) / this->size) + 1 << endl;
		this->shootgun(iterator);
		move_mouse();
		if (iterator == last_shooted) {
			this->delta -= 1;
		}
		iterator += this->delta * this->size;
	}
	printStep();
}

void MouseHunter::move_mouse() {
	register size_t total_byte = this->end - this->start;
	register size_t offset = 0;
	register bool can_be_move_here;
	char* next_step = (char*) calloc(total_byte / size, size);

	while (offset < total_byte) {
		can_be_move_here = this->is_true(this->start + offset);
		if (can_be_move_here && offset > 0) {
			memcpy(next_step + offset - this->size, this->start + offset,
					this->size);
		}

		if (can_be_move_here && (offset < total_byte - this->size)) {
			memcpy(next_step + offset + this->size, this->start + offset,
					this->size);
		}
		offset += this->size;
	}

	memcpy(this->start, next_step, total_byte);

}

}
