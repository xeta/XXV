#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "sorting.h"
#include <string>
#include <vector>
#include <sys/time.h>
#include <ctime>
#include "Generator.h"
#include "heap.h"
#include "gtest/gtest.h"

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

int main1(int argc, char **argv) {
	// Generator, that generates integers from 1..1000
	Generator g(1000);
	Collection c = g.generateVector(1000);

	test("STL Sort", Collection(c), sort);
	//	O(n*ln(2))
	test("Merge Sort", Collection(c), mergeSort);
	test("Insertion Merge Sort", Collection(c), insertionMergeSort);
	//	O(n**2)
	test("Insertion Sort", Collection(c), insertionSort);
	test("Bubble Sort", Collection(c), bubbleSort);

//	heap_type xxx[] = {0,1,2,3,4,5,6,7,8,9,10};
//
//
//	cout << "PARENT \n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[1]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[2]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[3]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[4]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[5]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[6]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[7]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[8]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[9]) <<"\n";
//	cout <<  " " <<*heap_parent(xxx, &xxx[10]) <<"\n";
//	cout << "LEFT \n";
//	cout <<  " " <<*heap_left(xxx, &xxx[0]) <<"\n";
//	cout <<  " " <<*heap_left(xxx, &xxx[1]) <<"\n";
//	cout <<  " " <<*heap_left(xxx, &xxx[2]) <<"\n";
//	cout <<  " " <<*heap_left(xxx, &xxx[3]) <<"\n";
//	cout <<  " " <<*heap_left(xxx, &xxx[4]) <<"\n";
//	cout << "RIGHT \n";
//	cout <<  " " <<*heap_right(xxx, &xxx[0]) <<"\n";
//	cout <<  " " <<*heap_right(xxx, &xxx[1]) <<"\n";
//	cout <<  " " <<*heap_right(xxx, &xxx[2]) <<"\n";
//	cout <<  " " <<*heap_right(xxx, &xxx[3]) <<"\n";
//	cout <<  " " <<*heap_right(xxx, &xxx[4]) <<"\n";
	return 0;
}

