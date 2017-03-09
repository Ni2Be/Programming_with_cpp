#include <iostream>

#include "Linked_List.h"

int main()
{
	try
	{
		const int MAX = 10;
		N2B::Linked_List list1;
		for (int i = 0; i < MAX; i++)
		{
			list1.add(i);
		}
		while (!list1.is_empty())
		{
			std::cout << list1.consume_first() << ", ";
		}
	}
	catch (std::exception &e)
	{

	}
	char ch;
	std::cin >> ch;
}