#include <iostream>

#include "Labyrinth.h"

int main()
{
	try
	{
		Labyrinth l1(3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
}