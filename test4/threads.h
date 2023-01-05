#pragma once
#include <thread>
#include <condition_variable>
#include <queue>
#include "message.h"

enum ThreadType {
	TIMER = 0,
	INPUT,
	UI
};
enum ThreadStatus {
	RUNNING,
	STOP
};

class ThreadRunnableBase {
public:
	ThreadRunnableBase(ThreadType t) :m_type(t) {}

	void start() { m_thread = std::thread(&ThreadRunnableBase::run,this); }
	void stop() { m_status = STOP; wakeup(); }
	void addTail(Message* msg) {
		std::lock_guard<std::mutex> lock(mt);
		message_queue.push(msg);
	}
	void wakeup() {
		wakeup_cv.notify_one();
	}
	bool isRunning() { return m_status == RUNNING; }


protected:
	void run() {
		m_status = RUNNING;
		mainProcessLoop();
	}
	virtual void mainProcessLoop() = 0;

	Message* getMessageFromQueue() {
		std::lock_guard<std::mutex> lock(mt);
		if (message_queue.empty())
			return nullptr;
		
		Message* ret = message_queue.front();
		message_queue.pop();
		return ret;
	}
protected:
	std::mutex mt;

	std::condition_variable wakeup_cv;
	std::queue<Message *> message_queue;
	std::thread m_thread;
	ThreadStatus m_status;
	ThreadType m_type;
};