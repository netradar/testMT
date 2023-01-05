#pragma once
#include "threads.h"
#include "Message.h"
#include <iostream>
#include "time_if.h"

class UIThread : public ThreadRunnableBase
{
public:
	UIThread():ThreadRunnableBase(UI),reinput_timer(Timer(4000,true)){
		
	}
protected:
	void mainProcessLoop() override;
	void processMessage(Message* msg);
	void getInput();

private:
	Timer reinput_timer;
};

