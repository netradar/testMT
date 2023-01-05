#pragma once
#include "threads.h"
#include "TimerMsg.h"
#include <list>

constexpr auto MAX_WAITING_TIME = 200;

class TimerThread : public ThreadRunnableBase
{
protected:
    void mainProcessLoop() override;
    void processMessage(Message* msg);
    void checkTimeout();
    void processTimeout();
private:
    std::list<TimerMsg*> m_registered_timer;
};

