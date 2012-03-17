#include "inversion.h"
using namespace std;
#define U_INT unsigned int

unsigned int merge_inversions(unsigned int* s1, size_t middle, size_t total) {
	U_INT inversions = 0;
	U_INT* iterator = s1;
	size_t size = sizeof(U_INT);
	U_INT* left_buffer = (U_INT*) malloc(size * middle);
	memcpy(left_buffer, s1, sizeof(U_INT) * middle);
	U_INT* left_buffer_end = left_buffer + middle;

	U_INT* right_buffer = (U_INT*) malloc(size * (total-middle));
	memcpy(right_buffer, s1+middle, sizeof(U_INT) * (total-middle));
	U_INT* right_buffer_end = right_buffer + (total-middle);

	while (left_buffer < left_buffer_end && right_buffer < right_buffer_end) {
		if (*left_buffer > *right_buffer) {
			memcpy(iterator, right_buffer, size);
			right_buffer++;
			inversions+=left_buffer_end-left_buffer;
		} else {
			memcpy(iterator, left_buffer, size);
			left_buffer++;
		}
		iterator++;
	}
	if (left_buffer == left_buffer_end) {
		memcpy(iterator, right_buffer, size*(right_buffer_end - right_buffer));
	}
	if (right_buffer == right_buffer_end) {
		memcpy(iterator, left_buffer, size*(left_buffer_end - left_buffer));
	}

	return inversions;
}

unsigned int count_inversions(unsigned int* start, size_t total) {
	if (total == 1) {
		return 0;
	}
	unsigned int result=0;
	size_t middle = total >> 0x01;
	result += count_inversions(start, middle);
	result += count_inversions(start + middle, total - middle);
	result += merge_inversions(start,middle,total);
	return result;
}

//unsigned int count_inversions(unsigned int* data, size_t total) {
//	unsigned int* end = data + total;
//	return inversions(data, end);
//}

