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

void TimerMsg::setLength(DURATION_10ms len)
{
	m_length = len;
}

void TimerMsg::setIsPeriodic(bool periodic)
{
	m_isPeriodic = periodic;
}

bool TimerMsg::isPeriodic()
{
	return m_isPeriodic;
}

DURATION_10ms TimerMsg::getLength()
{
	return m_length;
}


