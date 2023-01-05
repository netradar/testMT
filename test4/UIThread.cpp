#include "UIThread.h"
#include "InputThread.h"

void UIThread::mainProcessLoop()
{
	std::cout << "please enter a number:\n";

	getInput();
	reinput_timer.start();

	while (isRunning()) {

			Message* msg = getMessageFromQueue();

			if (!msg) {
				std::unique_lock<std::mutex> lock(mt);
				if (std::cv_status::timeout == wakeup_cv.wait_for(lock, std::chrono::milliseconds(MAX_WAITING_TIME)) || !isRunning()) {
					continue;
				}
				lock.unlock();

			}else
				processMessage(msg);

	}
	
}

void UIThread::processMessage(Message* msg)
{
	
	switch(msg->getType()){
	case TIMEOUT:
		std::cout << "no input,please input:\n";
		break;
	case GETINPUT:
		reinput_timer.stop();
		std::cout << "input coming!\n";
		break;
	}

	delete msg;
}

void UIThread::getInput()
{
	InputMsg* msg = new InputMsg();

	msg->setType(GETINPUT);
	msg->post(INPUT);
}
