


#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

typedef long Unicode;

//------------------------------------------------------------------------------

using namespace std;


template< class T> struct Vector : public std::vector<T> {
	using size_type = typename std::vector<T>::size_type;

#ifdef _MSC_VER
	// microsoft doesn't yet support C++11 inheriting constructors
	Vector() { }
	explicit Vector(size_type n) :std::vector<T>(n) {}
	Vector(size_type n, const T& v) :std::vector<T>(n, v) {}
	template <class I>
	Vector(I first, I last) : std::vector<T>(first, last) {}
	Vector(initializer_list<T> list) : std::vector<T>(list) {}
#else
	using std::vector<T>::vector;	// inheriting constructor
#endif

	T& operator[](unsigned int i) // rather than return at(i);
	{
		if (i<0 || this->size() <= i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
	const T& operator[](unsigned int i) const
	{
		if (i<0 || this->size() <= i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
};