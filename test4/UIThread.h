#pragma once
#include "threads.h"
#include <iostream>

class UIThread : public ThreadRunnableBase
{
protected:
	void mainProcessLoop() override;
};

