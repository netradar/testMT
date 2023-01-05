// test4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "threads.h"

using namespace std;


int main()
{


	auto t1 = std::chrono::steady_clock::now();
	auto t2 = std::chrono::steady_clock::now();
	t1 = t1 + 1s;

	cout << (t2 < t1);
}

