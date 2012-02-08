#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Sorting.h"
#include <vector>
#include <sys/time.h>
#include <ctime>
#include "Generator.h"

using namespace std;

template<typename Iterator>
void printArr(Iterator begin, Iterator end){
	Iterator it;
	cout << "[";
	for(Iterator it= begin; it!=end; ++it){
		if(it!=begin){
			cout << ", ";
		}
		cout << (*it);
	}
	cout << "]\n";
}

template<typename Iterator>
double benchmark(Iterator start, Iterator end ,void (*sort)(Iterator,Iterator)){
	timeval startTime, endTime;
	gettimeofday(&startTime,0);
	(*sort)(start,end);
	gettimeofday(&endTime,0);
	long seconds  = endTime.tv_sec  - startTime.tv_sec;
	long nseconds = endTime.tv_usec - startTime.tv_usec;
	return seconds + nseconds/1000000.0;
}

typedef int e_type;
typedef std::vector<int> Collection;
typedef Collection::iterator Iterator;

void insertion_sort(Iterator start, Iterator end) {
	e_type buf;
	Iterator it;
	for (it = start; it != end; ++it) {
		Iterator it_p = it - 1;
		while(*it_p > *(it_p+1)){
			buf = *it_p;
			*it_p = *(it_p+1);
			*(it_p+1) = buf;
			if(it_p==start){
				break;
			}
			it_p--;
		}
	}
}

int main(int argc, char **argv) {
	// Create vector generator
	Generator generator(200);

	// Generate vector with 100 elements
	vector<int> a = generator.generateVector(1000);

	cout << "Before sorting \n";
	printArr(a.begin(),a.end());

	double duration = benchmark(a.begin(), a.end(), insertion_sort);

	cout << "After sorting \n";
	printArr(a.begin(),a.end());

	printf("%5.6f seconds\n", duration);


	return 0;
}
