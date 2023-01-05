#include "UIThread.h"

void UIThread::mainProcessLoop()
{
	std::cout << "please enter a number:\n";

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
		std::cout << "no input time out:\n";
		break;
	}
}
