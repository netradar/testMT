#include "TimerThread.h"

void TimerThread::mainProcessLoop()
{

	while (isRunning()) {
		DURATION_10ms time_left = checkTimeout();

		if (time_left.count() > 0) {

			int ticks = time_left.count() * 10;
			if (ticks > MAX_WAITING_TIME)
				ticks = MAX_WAITING_TIME;

			Message* msg = getMessageFromQueue();

			if (!msg) {
				std::unique_lock<std::mutex> lock(mt);
				if (std::cv_status::timeout == wakeup_cv.wait_for(lock, std::chrono::milliseconds(ticks)) || !isRunning()) {
					continue;
				}
				//lock.unlock();
				//msg = getMessageFromQueue();
			}else
				processMessage(msg);

		}
		else {
			processTimeout();
		}
		

	}
	
}

void TimerThread::processMessage(Message* msg)
{

	switch (msg->getType()) 
	{
		case ADDTIMER:
			addTimer(static_cast<TimerMsg *>(msg));
			break;
	}
}

DURATION_10ms TimerThread::checkTimeout()
{
	if (m_registered_timer.empty())
		return DURATION_10ms(MAX_WAITING_TIME/10);
	return m_registered_timer.front()->getExpiredTime() - TimeManager::getCurrentTime();
}

void TimerThread::processTimeout()
{
	
	do {
		TimerMsg* msg = m_registered_timer.front();

		m_registered_timer.pop_front(); 
		if (msg->isPeriodic()) {
			TimerMsg* newMsg = new TimerMsg();
			memcpy(newMsg, msg, sizeof(TimerMsg));
			
			newMsg->setExpiredTime(TimeManager::getCurrentTime() + msg->getLength());
			addTimer(newMsg);
		}
		msg->setType(TIMEOUT);
		msg->post(msg->getSender());

	} while (checkTimeout().count() <= 0);
}

void TimerThread::addTimer(TimerMsg* msg)
{

	TIMEPOINT point = msg->getExpiredTime();
	
	auto it = m_registered_timer.begin();
	for (; it != m_registered_timer.end(); it++) {
		if ((*it)->getExpiredTime() > msg->getExpiredTime()) {
			break;
		}
	}
	m_registered_timer.insert(it, msg);


	
}
