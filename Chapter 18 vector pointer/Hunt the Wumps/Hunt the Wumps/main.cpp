#include <iostream>

#include "Labyrinth.h"

int main()
{
	try
	{
		N2B::Labyrinth l1(4, 3);

		bool game_running = true;
		char controller = 'r';
		int range = 3; //the range of the bow (3: 3 rooms)
		while (game_running)
		{
			//get connected rooms
			std::vector<N2B::Room*> connections = l1.get_room_connections(l1.player.position);
			for (auto connected_rooms : connections)
			{
				if (connected_rooms->bat_inside)
					std::cout << "I hear a Bat\n";
				else if (connected_rooms->has_hole)
					std::cout << "I feel a breeze\n";
				else if (connected_rooms->wumpus_inside)
					std::cout << "I can smell the Wumpus\n";
			}

			std::cout << "you see the rooms:\n";
			for (int i = 0; i < connections.size(); i++)
			{
				std::cout << connections[i]->name;
				if (i < connections.size() - 2)
					std::cout << ", ";
				else if (i == connections.size() - 2)
				{
					std::cout << " and ";
				}
			}
			while (controller == 'r')
			{
				std::cin.clear();
				std::cout << "\nwhat do you want to do?\nshoot (s) / move (m)\n";
				std::cin >> controller;
				std::cin.clear();

				int targeted_room = 0;
				if (controller == 's')
				{
					std::vector<N2B::Room*> shot;
					N2B::Room *arrow_position = l1.player.position;
					for (int i = 0; i < range; i++)
					{
						std::cout << "\nwhere do you want to shoot?\n";
						std::cout << "you see the rooms:\n";
						for (int n = 0; n < l1.get_room_connections(arrow_position).size(); n++)
						{
							std::cout << l1.get_room_connections(arrow_position)[n]->name;
							std::cout << " (" << n + 1 << ")";
							if (n < l1.get_room_connections(arrow_position).size() - 2)
								std::cout << ", ";
							else if (n == l1.get_room_connections(arrow_position).size() - 2)
							{
								std::cout << " and ";
							}
						}
						std::cout << std::endl;
						std::cin >> targeted_room;
						targeted_room -= 1;
						std::cin.clear();
						if (targeted_room < 0 || targeted_room >= connections.size())
						{
							std::cout << targeted_room << " is not valid target\n";
							i--;
						}
						else
						{
							shot.push_back(l1.get_room_connections(arrow_position)[targeted_room]);
							arrow_position = shot.back();
						}
					}
					bool hited_wumpus = l1.player.shoot(shot);
					controller = 'r';
				}
				else if (controller == 'm')
				{
					std::cout << "\nwhere do you want to move?\n";
					std::cin >> targeted_room;
					controller = 'r';
				}
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
}