#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <stdlib.h>
#include <stack>

template <typename T>
class Stack
{
private:
	int Size = 2;
	int Top = 0;
	T* arr;

	void Expand(int Multiplier);

public:
	Stack();
	Stack(T InitItem);

	void Push(T);
	T Pop();

	bool IsEmpty();

	void PrintStack();
};

#endif

