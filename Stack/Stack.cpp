#include "Stack.h"

template<typename T>
void Stack<T>::Expand(int Multiplier)
{
	T* NewArr = (T*)malloc(sizeof(T) * Size * Multiplier);
	for (int i = 0; i < Size; i++)
		NewArr[i] = arr[i];
	arr = NewArr;
	Size *= 2;
}

template<typename T>
Stack<T>::Stack()
{
	arr = (T*)malloc(sizeof(T)*Size);
}

template<typename T>
Stack<T>::Stack(T InitItem)
{
	arr = (T*)malloc(sizeof(T)*Size);
	arr[0] = InitItem;
}

template<typename T>
void Stack<T>::Push(T value)
{
	if (Top >= Size)
		Expand(2);

	arr[Top++] = value;
}

template<typename T>
T Stack<T>::Pop()
{
	if (Top == 0)
		return NULL;

	return arr[--Top];
}

template<typename T>
void Stack<T>::PrintStack()
{
	std::cout << "-----------------------------" << std::endl;
	
	for (int i = 0; i < Top; i++)
		std::cout << "Element " << i+1 << " =   " << arr[i] << std::endl;

	std::cout << "-----------------------------" << std::endl;
}
