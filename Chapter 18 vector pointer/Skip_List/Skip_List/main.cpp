#include <iostream>
#include "Skip_List.h"

int main()
{
	try
	{
		N2B::Skip_List list1;
		for (int i = 0; i < 10; i++)
		{
			list1.add(i);
		}
		while (!list1.is_empty())
		{
			std::cout << list1.front();
			list1.pop_front();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
}