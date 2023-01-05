#include "message.h"
#include "threads.h"
extern ThreadRunnableBase* thread_global[2];

void Message::post(ThreadType dest)
{

	thread_global[dest]->addTail(this);
	thread_global[dest]->wakeup();
	
}

void Message::reply()
{
	ThreadType t = sender;
	sender = receiver;
	receiver = t;
	post();
}
