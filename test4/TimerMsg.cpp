#include "TimerMsg.h"

bool TimerMsg::hasExpired()
{
	return TimeManager::getCurrentTime() >= expired_point;
}

bool TimerMsg::isExpiredAt(TIMEPOINT point)
{
	return expired_point >= point;
}

void TimerMsg::setSN(uint64_t sn)
{
	SN = sn;
}

void TimerMsg::setExpiredTime(TIMEPOINT point)
{
	expired_point = point;
}


