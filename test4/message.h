#pragma once
#include "globaldefine.h"

class Message {
public:
	void setType(MSG_TYPE type) {
		this->m_type = type;
	}
	MSG_TYPE getType();
	void post(ThreadType dest);
	void reply();
	void setSender(ThreadType s) { sender = s; }
	void setReceiver(ThreadType r) { receiver = r; }
	ThreadType getSender();
protected:
	MSG_TYPE m_type;
	ThreadType sender;
	ThreadType receiver;

};