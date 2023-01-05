#pragma once
#include "message.h"
#include <iostream>
#include "time_if.h"

class TimerMsg :  public Message
{
public:
	TimerMsg() :m_isPeriodic(false) { SN = 0; m_length = DURATION_10ms(0); }
	bool hasExpired();
	bool isExpiredAt(TIMEPOINT point);
	void setSN(uint64_t sn);
	void setExpiredTime(TIMEPOINT point);
	void setLength(DURATION_10ms len);
	void setIsPeriodic(bool periodic);
	bool isPeriodic();
	DURATION_10ms getLength();
	TIMEPOINT getExpiredTime() { return expired_point; }
private:
	TIMEPOINT expired_point;
	DURATION_10ms m_length;
	bool m_isPeriodic;
	int64_t SN = 0;
	
};

