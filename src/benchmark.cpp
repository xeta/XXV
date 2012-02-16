#include "benchmark.h"

void Benchmark::start() {
	gettimeofday(&startTime, 0);
}

double Benchmark::getTime() {
	timeval endTime;
	gettimeofday(&endTime, 0);
	long seconds = endTime.tv_sec - startTime.tv_sec;
	long nseconds = endTime.tv_usec - startTime.tv_usec;
	return seconds + nseconds / 1000000.0;
}
