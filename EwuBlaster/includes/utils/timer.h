#pragma once

#include <chrono>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePointClock;

class Timer {
public:
private:
	TimePointClock start_point;

public:
	Timer();
	void reset();
	float elapsed() const;
	float elapsedMillis() const;

private:
};
