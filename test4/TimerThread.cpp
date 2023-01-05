#include "TimerThread.h"

void TimerThread::mainProcessLoop()
{

	while (isRunning()) {
		DURATION_100ms time_left = m_registered_timer.front()->getExpiredTime() - TimeManager::getCurrentTime();

		if (time_left.count() > 0) {

			int ticks = time_left.count() * 100;
			if (ticks > MAX_WAITING_TIME)
				ticks = MAX_WAITING_TIME;

			Message* msg = getMessageFromQueue();

			if (!msg) {
				std::unique_lock<std::mutex> lock(mt);
				if (std::cv_status::timeout == wakeup_cv.wait_for(lock, std::chrono::milliseconds(ticks)) || !isRunning()) {
					continue;
				}
				msg = getMessageFromQueue();
			}
			processMessage(msg);

			checkTimeout();
		}
		else {
			processTimeout();
		}
		

	}
	
}

void TimerThread::processMessage(Message* msg)
{
}

void TimerThread::checkTimeout()
{
}

void TimerThread::processTimeout()
{
}
