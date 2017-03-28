#pragma once
#include <memory>
#include <algorithm>
#include "Allocator.h"

namespace not_std 
{
	template<class T, class A = not_std::allocator<T>>
	class vector
	{
	private:
		int sz;
		int space;
		T* elem;
		A alloc;
	public:
		vector() {}
		/*
		explicit vector(int size){}
		*/
		~vector() { delete(elem); }

		int size() const;
		int capacity() const;
		void resize(int, T);
		void push_back(const T&);
		void reserve(int new_alloc);

		T& operator[](int idx);
		const T& operator[](int idx) const;
		vector& operator=(const vector& a);
	};
}

template<class T, class A>
not_std::vector<T, A>& not_std::vector<T, A>::operator=(const not_std::vector<T, A>& a)
{
	this->alloc.deallocate(elem, space);
	this->elem = this->alloc.allocate(a.sz);
	for (int i = 0; i < a.sz; i++)
	{
		this->alloc.construct(&elem[i], a.elem[i]);
	}
	this->sz = a.sz;
	this->space = a.space; 
	return *this;
}

template<class T, class A> 
T& not_std::vector<T, A>::operator[](int idx)
{
	return this->elem[idx];
}

template<class T, class A> 
const T& not_std::vector<T, A>::operator[](int idx) const
{
	return this->elem[idx];
}

template<class T, class A> 
int not_std::vector<T, A>::size() const
{
	return this->sz;
}

template<class T, class A> 
int not_std::vector<T, A>::capacity() const
{
	return this->space;
}

template<class T, class A> 
void not_std::vector<T, A>::resize(int new_size, T def = T())
{
	reserve(new_size);
	for (int i = this->sz; i < new_size; i++)
	{
		this->alloc.construct(&this->elem[i], def);
	}
	for (int i = new_size; i < this->sz; i++)
	{
		this->alloc.construct(&this->elem[i], def);
	}
	this->sz = new_size;
}

template<class T, class A> 
void not_std::vector<T, A>::push_back(const T& value)
{
	if (this->space == 0) reserve(8); //start with 8 spaces
	else if (this->sz == this->space) reserve(2 * this->space); //if full make it as twice as big
	this->alloc.construct(&this->elem[sz], value);
	sz++;
}

//Private functions:
template<class T, class A> 
void not_std::vector<T, A>::reserve(int new_alloc)
{
	if (new_alloc <= this->space) return;
	T* p = this->alloc.allocate(new_alloc);
	for (int i = 0; i < this->sz; i++)
	{
		this->alloc.construct(&p[i], this->elem[i]);
	}
	for (int i = 0; i < sz; i++)
	{
		this->alloc.destroy(&this->elem[i]);
	}
	this->alloc.deallocate(elem, space);
	elem = p;
	space = new_alloc;
}