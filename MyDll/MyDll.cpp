#include "pch.h"
#include "MyDll.h"

__declspec(dllexport) int j = 10;
void printOut() {
	std::cout << "Print out\n";
}
void printOut2() {
	std::cout << "Print out2\n";
}

void MyClass1::func()
{
	std::cout << "func changed\n";
}
