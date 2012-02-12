#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Sorting.h"
#include <string>
#include <vector>
#include <sys/time.h>
#include <ctime>
#include "Generator.h"

using namespace std;

template<typename Iterator>
void printArr(Iterator begin, Iterator end) {
	Iterator it;
	cout << "[";
	for (Iterator it = begin; it != end; ++it) {
		if (it != begin) {
			cout << ", ";
		}
		cout << (*it);
	}
	cout << "]\n";
}

template<typename C>
double benchmark(C start, C end, void(*sort)(C, C)) {
	timeval startTime, endTime;
	gettimeofday(&startTime, 0);
	(*sort)(start, end);
	gettimeofday(&endTime, 0);
	long seconds = endTime.tv_sec - startTime.tv_sec;
	long nseconds = endTime.tv_usec - startTime.tv_usec;
	return seconds + nseconds / 1000000.0;
}

bool isSorting(Iterator begin, Iterator end) {
	while (begin < end - 1) {
		if (*begin > *(begin + 1))
			return false;
		begin++;
	}
	return true;
}

void test(string name, Collection c, void(*fnc)(Iterator, Iterator)) {

	cout << name << "\n";

//	cout << "-----------------------------------------------------------------\n";
//	cout << "Before sorting: ";
//	printArr(c.begin(), c.end());
	double duration = benchmark(c.begin(), c.end(), fnc);

//	cout << "After sorting:  " ;
//	printArr(c.begin(), c.end());

	if(isSorting(c.begin(), c.end()))
		cout << "[Done] \n";
	else
		cout << "[Fail] \n";

	printf("Total time: %5.6f seconds\n", duration);
	cout << "-----------------------------------------------------------------\n";
}

int main(int argc, char **argv) {
	// Generator, that generates integers from 1..1000
	Generator g(1000);
	Collection c = g.generateVector(100);

	test("STL Sort", Collection(c), sort);
	test("Merge Sort", Collection(c), mergeSort);
	test("Insertion Merge Sort", Collection(c), insertionMergeSort);
	test("Insertion Sort", Collection(c), insertionSort);
	test("Bubble Sort", Collection(c), bubbleSort);

	return 0;
}
