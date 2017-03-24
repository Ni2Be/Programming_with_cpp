#pragma once
#include <iostream>

namespace N2B
{
	template <class T> struct S;
	template <class T> std::istream& operator>>(std::istream& is, S<T>& t);
	template <class T> std::ostream& operator<<(std::ostream& os, const S<T>& t);

	template <class T>
	struct S
	{
	public:
		S(T t)
			:val(t) { }

		T& get();
		S& operator=(T);
		T& operator[](int);
		const T& operator[](int) const;
		friend std::istream& operator>> <T> (std::istream& is, S<T>& t);
		friend std::ostream& operator<< <T> (std::ostream& os, const S<T>& t);
	private:
		T val;
	};

	template <class T>
	T& S<T>::get()
	{
		return val;
	}

	template<class T>
	S<T>& S<T>::operator=(T t)
	{
		return *this;
	}

	template<class T>
	T& S<T>::operator[](int i)
	{
		return val;
	}
	
	template<class T>
	const T& S<T>::operator[](int i) const
	{
		return val;
	}

	template <class T>
	std::istream& operator>>(std::istream& is, S<T>& t)
	{
		is >> t.val;
		return is;
	}

	template <class T>
	std::ostream& operator<<(std::ostream& os, const S<T>& t)
	{
		return os << t.val;
	}
}