#include "Src/Stack.h"
#include "Src/DynamicArray.h"
#include "Src/Queue.h"
#include "Src/List.h"

#define LIST

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

	ADS::Queue<int> IntQueue = ADS::Queue<int>();
	IntQueue.Enqueue(1);
	IntQueue.Enqueue(2);
	IntQueue.Enqueue(3);
	IntQueue.Enqueue(4);
	IntQueue.Enqueue(5);
	int i = IntQueue.Dequeue().value();
	std::cout << i << std::endl;
	IntQueue.Dequeue();
	IntQueue.Dequeue();
	IntQueue.Dequeue();
	IntQueue.Dequeue();
	IntQueue.Enqueue(6);
	IntQueue.Enqueue(7);
	IntQueue.Enqueue(8);
	IntQueue.Print();

#endif //  QUEUE

#ifdef LIST

	int says[5] = {1, 2, 3, 4,5};

	List<int> l = List<int>(says,sizeof(says)/sizeof(says[0]));

	l.Append(32);
	l.Append(12);
	l.Append(52);
	l.Append(72);
	l.Append(72);
	l.Pop();
	l.Pop();
	l.Remove(4);

	l.Print();


#endif // LIST


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