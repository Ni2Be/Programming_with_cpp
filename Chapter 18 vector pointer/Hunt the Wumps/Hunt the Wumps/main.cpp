/**
If the program does not work, it is probably becouse of the
random_device, just use an onther random number generator.

@author Jordan
@version 1.0 03/15/17
*/

#include <iostream>

#include "HtW_Game.h"

int main()
{
	try
	{
		bool run = true;
		while (run == true)
		{
			std::cout << "Set size of the Labyrinth, and difficulty\n"
				<< "like: 3 3\n";
			int size = 0, dif = 0;
			std::cin >> size >> dif;
			N2B::HtW_Game game(size, dif);
			game.start();

			std::cout << "\nPlay again? y / n\n";
			char answer;
			std::cin >> answer;
			(answer == 'y') ? run = true : run = false;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
}