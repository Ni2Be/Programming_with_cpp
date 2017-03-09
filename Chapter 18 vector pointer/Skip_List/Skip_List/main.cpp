#include <iostream>
#include "Skip_List.h"

int main()
{
	try
	{
		Skip_List list1();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
}