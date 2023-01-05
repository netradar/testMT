#pragma once
#include "threads.h"

enum MSG_TYPE {
	ADDTIMER,
	CANCELTIMER,
	TIMEOUT
};
class Message {
public:
	void setMessageType(MSG_TYPE type) {
		this->m_type = type;
	}
	void post(ThreadType dest);
	void reply();
	void setSender(ThreadType s) { sender = s; }
	void setReceiver(ThreadType r) { receiver = r; }
protected:
	MSG_TYPE m_type;
	ThreadType sender;
	ThreadType receiver;
};