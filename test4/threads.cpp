#include "threads.h"

ThreadRunnableBase* thread_global[2];

static thread_local ThreadType s_thread_type;