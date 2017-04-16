#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <iterator>


namespace Test_Area
{
	class Item
	{
	public:
		std::string name;
		int iid;
		double value;

		Item() {}
		Item(std::string s, int id, double val)
			:name(s), iid(id), value(val) {}
	};

	std::ostream& operator<<(std::ostream& os, const Item& i);
	std::istream& operator>>(std::istream& is, Item& i);

	template <class T>
	T& read_ff(std::string file)
	{

		std::ifstream is(file.c_str());

		std::istream_iterator<T::value_type> ii(is);
		std::istream_iterator<T::value_type> eos;

		std::unique_ptr<T> data(new T(ii, eos));
		return *data.release();
	}

	template <class T>
	void print_items(const T& i)
	{
		for (T::const_iterator iter = i.begin(); iter != i.end(); iter++)
			std::cout << *iter << std::endl;
	}
}