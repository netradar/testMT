#pragma once
#include <thread>

using DURATION_10ms = std::chrono::duration<int, std::ratio<1, 100>>;
typedef   std::chrono::time_point<std::chrono::steady_clock, DURATION_10ms> TIMEPOINT;

class TimeManager {
public:
	inline static TIMEPOINT getCurrentTime() {
		return std::chrono::time_point_cast<DURATION_10ms>(std::chrono::steady_clock::now());
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
	Timer(int length_ms, bool _isPeriodic = false) :length(length_ms),SN(0),isPeriodic(_isPeriodic) {}
	void start();
	void stop();
	void reset();

private:
	int length;
	bool isPeriodic;
	uint64_t SN;
};

