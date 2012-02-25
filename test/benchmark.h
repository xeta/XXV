#ifndef BENCHMARK_H_
#define BENCHMARK_H_
#include <sys/time.h>

class Benchmark {
public:
	Benchmark(){};
	void start();
	double getTime();
private:
	timeval startTime;
};

#endif
