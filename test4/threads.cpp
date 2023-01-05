#include "threads.h"

ThreadRunnableBase* thread_global[ThreadNum]{};

thread_local ThreadType s_thread_type;

void ThreadRunnableBase::run(){
	m_status = RUNNING;
	s_thread_type = m_type; 
	mainProcessLoop();
}
