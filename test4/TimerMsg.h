#pragma once
#include "message.h"
#include <iostream>
#include "time_if.h"

class TimerMsg :  public Message
{
public:
	bool hasExpired();
	bool isExpiredAt(TIMEPOINT point);
	void setSN(uint64_t sn);
	void setExpiredTime(TIMEPOINT point);
	TIMEPOINT getExpiredTime() { return expired_point; }
private:
	TIMEPOINT expired_point;
	int64_t SN;
	
};

