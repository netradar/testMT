#pragma once

#include <iostream>

 __declspec(dllexport) void printOut();
void printOut2();

class  MyClass1 {
public:
	__declspec(dllexport) void func();
	void func2() { std::cout << "func2\n"; }

public:
	int x = 8;

};