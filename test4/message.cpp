#include "message.h"
#include "threads.h"
#include <iostream>

extern ThreadRunnableBase* thread_global[3];
extern thread_local ThreadType s_thread_type;

MSG_TYPE Message::getType()
{
	return m_type;
}

void Message::post(ThreadType dest)
{
	
	sender = s_thread_type;
	receiver = dest;
	thread_global[dest]->addTail(this);
	thread_global[dest]->wakeup();

	
}

void Message::reply()
{
	std::cout << "reply message\n";
	post(sender);
}

ThreadType Message::getSender()
{
	return sender;
}
