// test4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "globaldefine.h"
#include "TimerThread.h"
#include "UIThread.h"
#include "InputThread.h"


using namespace std;

extern ThreadRunnableBase* thread_global[3];
int main()
{

	thread_global[TIMER] = new TimerThread();
	thread_global[INPUT] = new InputThread();
	thread_global[UI] = new UIThread();

	thread_global[INPUT]->start();
	thread_global[TIMER]->start();

	thread_global[UI]->start();

	thread_global[UI]->join();



	
}

