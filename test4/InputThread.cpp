#include "InputThread.h"
#include <string>
void InputThread::mainProcessLoop()
{
	while (isRunning()) {

		Message* msg = getMessageFromQueue();

		if (!msg) {
			std::unique_lock<std::mutex> lock(mt);
			if (std::cv_status::timeout == wakeup_cv.wait_for(lock, std::chrono::milliseconds(MAX_WAITING_TIME)) || !isRunning()) {
				continue;
			}
			lock.unlock();

		}
		else
			processMessage(static_cast<InputMsg *>(msg));

	}
}

void InputThread::processMessage(InputMsg* msg)
{
	switch (msg->getType())
	{
	case GETINPUT:
		std::string *s = new std::string();
		std::getline(std::cin, *s);
		msg->setData(s);
		msg->reply();
		break;
	}
}
