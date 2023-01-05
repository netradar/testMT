#include "time_if.h"

void Timer::start()
{
	TimerMsg* msg = new TimerMsg();
	msg->setMessageType(ADDTIMER);

	SN = TimeManager::getSN();
	msg->setSN(SN);
	msg->setExpiredTime(TimeManager::getCurrentTime() + DURATION_100ms(length));
	msg->post(TIMER);

}

void Timer::stop()
{
}

void Timer::reset()
{
}
