#include "sorting.h"

void heapSort(void * const root, void * const end, size_t size,
		__comporator cmp) {
	register char* _first = (char*) root;
	register char* _last = (char*) end - size;

	// Create heap structure from root pointer
	build_heap(root, end, size, cmp);

	while (_first != _last) {
		SWAP(_first, _last, size);
		_last -= size;
		max_heapify(_first, _first, _last + size, size, cmp);
	}
}

//TODO this function need to be rewritten
void insertionSort(void * const _start, void * const _end, size_t size,
		__comporator cmp) {
	register char* iterator = (char*) _start;
	register char* end = (char*) _end;

	register char* j;
	register char* j_pr;
	while (iterator < end) {
		j = iterator;
		j_pr = j - size;
		while (j > _start && (*cmp)((void *) j, (void *) (j_pr))) {
			SWAP(j_pr, j, size);
			j = j_pr;
			j_pr -= size;
		}
		iterator += size;
	}
}

void merge(const void* _start, const void* _middle, const void* _end,
		size_t size, __comporator cmp) {

	register char* iterator = (char*) _start;
	size_t left_size = (char*) _middle - iterator;
	size_t right_size = (char*) _end - (char*) _middle;

	register char* left_buffer = (char*) malloc(left_size);
	memcpy(left_buffer, iterator, left_size);
	char* left_buffer_end = left_buffer + left_size;

	register char* right_buffer = (char*) malloc(right_size);
	memcpy(right_buffer, (char*) _start + left_size, right_size);
	char* right_buffer_end = right_buffer + right_size;

	while (left_buffer < left_buffer_end && right_buffer < right_buffer_end) {
		if ((cmp)(left_buffer, right_buffer)) {
			memcpy(iterator, left_buffer, size);
			left_buffer += size;
		} else {
			memcpy(iterator, right_buffer, size);
			right_buffer += size;
		}
		iterator += size;
	}
	if (left_buffer == left_buffer_end) {
		memcpy(iterator, right_buffer, (right_buffer_end - right_buffer));
	}
	if (right_buffer == right_buffer_end) {
		memcpy(iterator, left_buffer, (left_buffer_end - left_buffer));
	}

}
void mergeSort(void * const _start, void* const _end, size_t size,
		__comporator cmp) {
	char* start = (char*) _start;
	char* end = (char*) _end;

	if (start == end - size)
		return;

	size_t dif = (end - start) >> 0x01;
	char* middle = start + dif - (dif % size);

	mergeSort(start, middle, size, cmp);
	mergeSort(middle, end, size, cmp);
	merge(start, middle, end, size, cmp);
}

char* quickPartition(void * const root, void * const end, size_t size,
		__comporator cmp) {

	register char* part = (char*) root;
	register char* iterator = (char*) root;
	register char* last = (char*) end - size;
	//just add randomization
	if ((last - part) > size << 0x06) {
		SWAP(iterator+(rand() % ((last - part) / size))*size, last, size);
	}

	while (iterator != last) {
		if ((cmp)(iterator, last)) {
			SWAP(iterator, part, size);
			part += size;
		}
		iterator += size;
	}

	SWAP(part, last, size);

	return part;
}

//void quickSort(void * const root, void * const end, size_t size,
//		__comporator cmp) {
//	if (root == end || root == (char*) end - size)
//		return;
//	char* partition = quickPartition(root, end, size, cmp);
//	quickSort(root, partition, size, cmp);
//	quickSort(partition, end, size, cmp);
//}

void quickSort(void * const root, void * const end, size_t size,
		__comporator cmp) {
	register part_t part = { (char*) root, (char*) end };

	register std::stack<part_t> queue;
	queue.push(part);
	register char* partition;
	while (!queue.empty()) {
		part = queue.top();
		queue.pop();
		partition = quickPartition(part.begin, part.end, size, cmp);

		if (partition != part.begin && partition != part.begin + size) {
			part_t part1 = { part.begin, partition };
			queue.push(part1);
		}
		if (partition != part.end && partition != part.end - size) {
			part_t part2 = { partition, part.end };
			queue.push(part2);
		}
	}
}

