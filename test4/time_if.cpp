#include "time_if.h"
#include "TimerMsg.h"

void Timer::start()
{
	TimerMsg* msg = new TimerMsg();
	msg->setType(ADDTIMER);

	SN = TimeManager::getSN();
	msg->setSN(SN);
	msg->setExpiredTime(TimeManager::getCurrentTime() + DURATION_10ms(length/10));
	msg->setIsPeriodic(isPeriodic);
	msg->setLength(DURATION_10ms(length / 10));
	msg->post(TIMER);

}

void Timer::stop()
{
}

void Timer::reset()
{
}
