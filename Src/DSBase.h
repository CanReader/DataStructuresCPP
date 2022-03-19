#ifndef _BSBASE_H_
#define _BSBASE_H_

#include <iostream>
#include <stdlib.h>
#include <optional>

#define ExecuteIfBigger(Size,Capacity) if(Capacity <= Size)
#define RunForSize(Size) for(int i = 0; i < Size; i++)

namespace ADS
{

template<typename T>
class IDSBase
{
public:
	virtual void Print() = 0;
	virtual bool IsEmpty() { return this->Size == 0; }
	virtual int GetSize() { return this->Size; }
	virtual void Clear() = 0;
	
	virtual void Expand(int Multiplier)
	{
		this->Capacity *= Multiplier;

		T* Newarr = (T*)malloc(sizeof(T) * this->Capacity);

		for (int i = 0; i < this->Size; i++)
			Newarr[i] = this->arr[i];

		this->arr = Newarr;
	}

protected:
	bool CheckSize()
	{
		return Size >= Capacity;
	}

	int Size = 0;
	int Capacity = 2;

	T* arr;
};

}
#endif // !

