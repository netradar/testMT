#pragma once
#include "threads.h"
#include "TimerMsg.h"
#include <list>


class TimerThread : public ThreadRunnableBase
{
public:
    TimerThread() :ThreadRunnableBase(TIMER) {}
protected:
    void mainProcessLoop() override;
    void processMessage(Message* msg);
    DURATION_10ms checkTimeout();
    void processTimeout();
    void addTimer(TimerMsg* msg);
private:
    std::list<TimerMsg*> m_registered_timer;
};

