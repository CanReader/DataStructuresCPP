#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "DSBase.h"

namespace ADS
{
	template<typename T>
	class DynamicArray : public IDSBase<T>
	{
	public:
		DynamicArray()
		{
			this->arr = (T*)malloc(sizeof(T) * 2);
		}

		DynamicArray(T InitItem)
		{
			this->arr = (T*)malloc(sizeof(T) * 2);
			Insert(0,InitItem);
		}

		DynamicArray(T* InitItem) 
		{
			this->arr = InitItem;
		}

		~DynamicArray()
		{
			this->arr = nullptr;
		}

		friend std::ostream& operator << (std::ostream& out, const DynamicArray<T>& c) 
		{
			out << std::endl;

			std::cout << "*---------------------- Dynamic Array ----------------------*" << std::endl;

			for (int i = 0; i < c.Size; i++)
				out << "Element " << i + 1 << ": " << c.arr[i] << std::endl;

			std::cout << "*--------------------------------------------*" << std::endl;

			return out;
		}

		T& operator+=(const T& Value)
		{
			Add(Value);
			return *this;
		}

		T& operator[](int Index) 
		{
			return this->arr[Index];
		}

		void Insert(int Index, const T Value);
		T& At(int Index);
		void Add(const T Value);
		void EraseAt(int Index) noexcept;
		void Erase(const T& Value) noexcept;

		int  IndexOf(const T Value) noexcept;
		bool Contains(const T Value) noexcept;
		void Reverse();
		T* Copy();

		void Print();
		void Clear();

	private:
	};

	template<typename T>
	inline void DynamicArray<T>::Insert(int Index, const T Value)
	{
		if (Index >= 0 && Index < this->Size)
		{
			this->arr[Index] = Value;
		}
	}

	template<typename T>
	inline void DynamicArray<T>::Add(const T Value)
	{
		ExecuteIfBigger(this->Size, this->Capacity)
			this->Expand(2);

		this->arr[this->Size++] = Value;
	}

	template<typename T>
	inline T& DynamicArray<T>::At(int Index)
	{
		if (Index < 0)
		{
			Index *= -1;
		}

		return this->arr[Index % (this->Size-1)];
	}

	template<typename T>
	inline void DynamicArray<T>::EraseAt(int Index) noexcept
	{
		if (Index > 0 && Index < this->Size)
		{
		 for (int i = Index; i < this->Size - 2; i++)
			this->arr[i] = this->arr[i+1];

		 this->Size--;
		 this->Expand(1);
		}
	}

	template<typename T>
	inline void DynamicArray<T>::Erase(const T& Value) noexcept
	{
		for (int i = 0; i < this->Size; i++)
			if (this->arr[i] == Value)
				Erase(i);
	}

	template<typename T>
	inline int DynamicArray<T>::IndexOf(const T Value) noexcept
	{
		for (int i = 0; i < this->Size; i++)
			if (this->arr[i] == Value)
				return i;
		return -1;
	}

	template<typename T>
	inline bool DynamicArray<T>::Contains(const T Value) noexcept
	{
		for (int i = 0; i < this->Size; i++)
			if (this->arr[i] == Value)
				return true;
		return false;
	}

	template<typename T>
	inline T* DynamicArray<T>::Copy()
	{
		T* NewArr = (T*)malloc(sizeof(T)*this->Size);

		for (int i = 0; i < this->Size; i++)
			NewArr[i] = this->arr[i];

		return NewArr;
	}

	template<typename T>
	inline void DynamicArray<T>::Print()
	{
		std::cout << "*---------------------- Dynamic Array ----------------------*" << std::endl;

		for (int i = 0; i < this->Size; i++)
			std::cout << "Element " << i+1 << ":  " << this->arr[i] << std::endl;

		std::cout << "*--------------------------------------------*" << std::endl;
	}

	template<typename T>
	inline void DynamicArray<T>::Clear()
	{
		this->arr = (T*)malloc(sizeof(T)*2);
		this->Size = 0;
		this->Capacity = 2;
	}
}


#endif