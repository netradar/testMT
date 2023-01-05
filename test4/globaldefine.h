#pragma once
enum ThreadType {
	TIMER = 0,
	INPUT,
	UI
};
enum ThreadStatus {
	RUNNING,
	STOP
};

enum MSG_TYPE {
	ADDTIMER,
	CANCELTIMER,
	TIMEOUT
};