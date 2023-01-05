#pragma once
enum ThreadType {
	TIMER = 0,
	INPUT,
	UI
};
constexpr int ThreadNum = UI + 1;
enum ThreadStatus {
	RUNNING,
	STOP
};

enum MSG_TYPE {
	ADDTIMER,
	CANCELTIMER,
	TIMEOUT,
	GETINPUT
};