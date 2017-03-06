#pragma once

namespace not_std {
	template<class T> class vector
	{
	private:
		int sz;
		int space;
		T* elem;
		

		void reserve(int new_alloc);
		void copy(const vector<T>& arg);
	public:
		vector() :sz(0), elem(0), space(0) {}

		explicit vector(int size)
			:sz(size), elem(new T[size]), space(size)
		{ for (int i = 0; i < sz; i++) { elem[i] = 0; } }

		~vector() { delete(elem); }

		int size() const;
		int capacity() const;
		void resize(int, T);
		void push_back(T);

		vector(const vector<T>&);
		T& operator[](int idx);
		const T& operator[](int idx) const;
		vector<T>& operator=(const vector<T>&);
	};
}
#include "vector.h"


//Copy constructor:
template<class T> not_std::vector<T>::vector(const vector<T>& ref)
	:sz(ref.sz), elem(new T[ref.sz])
{
	copy(ref);
}

//Operator:
template<class T> not_std::vector<T>& not_std::vector<T>::operator=(const vector<T>& ref)
{
	if (this == &ref) return *this;
	if (sz >= ref.sz)
	{
		sz = ref.sz;
		for (int i = 0; i < sz; i++)
		{
			elem[i] = ref.elem[i];
		}
		return *this;
	}


	T *elemP = new T(ref.sz);
	for (int i = 0; i < ref.sz; i++)
	{
		elemP[i] = ref.elem[i];
	}
	delete[] elem;
	elem = elemP;
	space = sz = ref.sz;
	return *this;
}

template<class T> T& not_std::vector<T>::operator[](int idx)
{
	return elem[idx];
}

template<class T> const T& not_std::vector<T>::operator[](int idx) const
{
	return elem[idx];
}

//Public functions:
template<class T> int not_std::vector<T>::size() const
{
	return sz;
}

template<class T> int not_std::vector<T>::capacity() const
{
	return space;
}

template<class T> void not_std::vector<T>::resize(int new_size, T def = T())
{
	reserve(new_size);
	for (int i = sz; i < space; i++)
	{
		elem[i] = def;
	}
	sz = new_size;
}

template<class T> void not_std::vector<T>::push_back(T value)
{
	if (space == 0) reserve(8); //start with 8 spaces
	else if (sz == space) reserve(2 * space); //if full make it as twice as big
	elem[sz] = value;
	sz++;
}

//Private functions:
template<class T> void not_std::vector<T>::reserve(int new_alloc)
{
	if (new_alloc < space) return;
	T* tempP = new T[new_alloc];
	for (int i = 0; i < sz; i++)
	{
		tempP[i] = elem[i];
	}
	delete[] elem;
	elem = tempP;
	space = new_alloc;
}

template<class T> void not_std::vector<T>::copy(const vector& arg)
{
	for (int i = 0; i < sz; i++)
	{
		elem[i] = arg.elem[i];
	}
}
