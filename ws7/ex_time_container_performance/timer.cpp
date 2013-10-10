#include "timer.h"

std::chrono::microseconds time_func(void  (f)()){
	std::chrono::high_resolution_clock clock{};
	auto start=clock.now();
		f();
	auto end = clock.now();
	using std::chrono::microseconds;
	return std::chrono::duration_cast<microseconds>(end - start);
}
