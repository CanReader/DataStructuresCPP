#include "Stack/stack.h"

#include <functional>

#define OTHERS

class classf
{
public:
	classf()
	{
	}

	double operator() (double x)
	{
		return 10 * x;
	}	
};

template<class T>
struct negate : public unary_function<T, T>
{
	T operator() (const T& x) const
	{
		return -x;
	}
};

double sum(classf f, int n, int m)
{
	double result = 0;

	for (int i = n; i <= m; i++)
		result += f(i);

	return result;
}

int main(int argc, char** argv)
{

#ifdef STACK


	Stack<int> StackInt = Stack<int>();
	StackInt.Push(5);
	StackInt.Push(23);
	StackInt.Push(65);
	StackInt.Push(21);
	StackInt.Push(64);
	StackInt.Push(74);
	StackInt.Push(99);

	StackInt.PrintStack();

	Stack<const char*> StackStr = Stack<const char*>();
	StackStr.Push("Test1");
	StackStr.Push("Test2");
	StackStr.Pop();
	StackStr.Push("Test3");
	StackStr.Push("Test4");


	StackStr.PrintStack();

#endif // STACK
	
#ifdef Queue
#endif Queue

#ifdef LINKEDLIST
#endif // LINKEDLIST

#ifdef OTHERS
	std::cout << sum(classf(),2,5);
#endif

	std::cin;

	return 1;
}

