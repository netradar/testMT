#include "threads.h"

ThreadRunnableBase* thread_global[3]{};

thread_local ThreadType s_thread_type;

void ThreadRunnableBase::run(){
	m_status = RUNNING;
	s_thread_type = m_type; 
	mainProcessLoop();
}
