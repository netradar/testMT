#pragma once
#include "threads.h"
#include "message.h"

class InputMsg : public Message {
public:
	
	void setData(void* _data) { data = _data; }
	void setDataLength(int len) { data_lenth = len; }
private:
	void* data;
	int data_lenth;
};
class InputThread :  public ThreadRunnableBase
{
public:
	InputThread() :ThreadRunnableBase(INPUT) {}
protected:
	void mainProcessLoop() override;
private:
	void processMessage(InputMsg* msg);
};

