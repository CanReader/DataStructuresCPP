#include "Src/Stack.h"
#include "Src/DynamicArray.h"

#define OTHERS

int main()
{
#ifdef STACK

	ADS::Stack<int> IntStack = ADS::Stack<int>(1);

	IntStack.Push(43);
	IntStack.Push(7);
	IntStack.Push(61);
	IntStack.Push(374);
	IntStack.Push(58);
	IntStack.Push(92);
	IntStack.Push(89);

	std::cout << "Popped: " << IntStack.Pop() << std::endl;
	std::cout << "Popped: " << IntStack.Pop() << std::endl;
	std::cout << "Popped: " << IntStack.Pop() << std::endl;
	std::cout << "Popped: " << IntStack.Pop() << std::endl;
								
	std::cout << IntStack;

#endif // STACK

#ifdef  QUEUE

#endif //  QUEUE

#ifdef BT

#endif // BT

#ifdef OTHERS

	ADS::DynamicArray<int> IntArray = ADS::DynamicArray<int>();
	for (int i = 0; i < 100; i++)
		IntArray.Add(i);

	for (int i = 0; i >= -100; i--)
		IntArray.Insert((i*(-1)),i*3131);

	std::cout << IntArray << std::endl;

	std::cout << IntArray.At(3) << "is at index 3" << std::endl;

	int x = 99;
	bool result = IntArray.Contains(x);
	if (result)
		std::cout << x << " is at the array!" << std::endl;
	else
		std::cout << x << " is not at the array!" << std::endl;

	std::cout << "index of " << x << " is " << IntArray.IndexOf(x) << std::endl;
	x = IntArray.At(63);
	std::cout << "index of " << x << " is " << IntArray.IndexOf(x) << std::endl;

	IntArray.EraseAt(6);

	IntArray.Print();

#endif // OTHERS

	return 0;
}