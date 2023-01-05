#pragma once


enum ThreadType {
	TIMER = 0,
	UI
};

enum MSG_TYPE {
	ADDTIMER,
	CANCELTIMER,
	TIMEOUT
};