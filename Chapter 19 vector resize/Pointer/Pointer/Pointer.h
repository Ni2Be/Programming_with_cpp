#pragma once
#include <iostream>

namespace not_std
{
	template <class T>
	class counted_pointer
	{
	public:
		T* p;
		int* counter;

		counted_pointer(T* pointer, int* c)
		:p(pointer), counter(c){}

		counted_pointer(T* pointer)
		:p(pointer), counter(new int(1)) {}

		counted_pointer(counted_pointer<T>& cp)
		{
			cp.get_counter()++;
			this->p = cp.p;
			this->counter = cp.counter;
		}


		~counted_pointer()
		{
#ifndef RAMTEST
			std::cout << "destructor\n" << counter << ": val:" << *counter <<  std::endl;
#endif
			(*counter)--;
			if (*counter == 0)
			{
#ifndef RAMTEST
				std::cout << "delete\n" << counter << ": val:" << *counter << std::endl;
#endif
				delete counter;
				delete p;
			}
		}
		
		T* release();
		counted_pointer& copy();
		int& get_counter();

		T* operator->()
		{
			return p;
		}

		T& operator*()
		{
			return *p;
		}
	};

	template <class T>
	T* counted_pointer<T>::release()
	{
		T* temp = p;
		(*counter)--;
		if (*counter == 0)
		{
			p = 0;
			counter = 0;
			delete this;
		}
		return temp;
	}

	template <class T>
	counted_pointer<T>& counted_pointer<T>::copy()
	{
		this->get_counter()++;
		return counted_pointer<T>(this->p, &this->get_counter());
	}

	template <class T>
	int& counted_pointer<T>::get_counter()
	{
		return *counter;
	}
}
