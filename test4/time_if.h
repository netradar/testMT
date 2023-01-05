#pragma once
#include "TimerMsg.h"
#include <thread>

using DURATION_100ms = std::chrono::duration<int, std::ratio<1, 10>>;
using TIMEPOINT = std::chrono::time_point<std::chrono::steady_clock, DURATION_100ms>;

class TimeManager {
public:
	inline static TIMEPOINT getCurrentTime() {
		return std::chrono::time_point_cast<DURATION_100ms>(std::chrono::steady_clock::now());
	}
	inline static uint64_t getSN() {
		static uint64_t serial_number = 0;
		if (serial_number == 0) {
			++serial_number;
		}
		return serial_number;
	}
};
class Timer{
public:
	Timer(int length_ms) :length(length_ms) {}
	void start();
	void stop();
	void reset();

private:
	int length;
	uint64_t SN;
};

