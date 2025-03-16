
#include <utils/timer.h>


Timer::Timer() {
	reset();
}
void Timer::reset() {
	start_point = std::chrono::high_resolution_clock::now();
}

float Timer::elapsed() const {
	return elapsedMillis() * 0.001f;
}
float Timer::elapsedMillis() const {
	TimePointClock this_point = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(this_point - start_point).count() * 0.001f;
}
