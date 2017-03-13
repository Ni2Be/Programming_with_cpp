#include "Labyrinth.h"



Labyrinth::Labyrinth(int size)
{
	labyrinth = generate_wing();
	for (int i = 0; i < size; i++)
	{
		std::vector<std::vector<Room*>> wing;
		wing = generate_wing();
		labyrinth = merge_wings(labyrinth, wing);
#ifdef DEBUG
		std::cout << "DEBUG:\n";
		this->print();
		std::cout << "END DEBUG\n";
#endif //DEBUG
	}
}


Labyrinth::~Labyrinth()
{
	//TODO
}

std::vector<std::vector<Room*>> Labyrinth::generate_wing()
{
	std::vector<std::vector<Room*>> wing;

	for (int i = 0; i < 4; i++)
	{
		std::vector<Room*> row;
		for (int n = 0; n < 4; n++)
		{
			if (n == i)
			{
				row.push_back(0);
				continue;
			}
			Room* room = new Room();
			row.push_back(room);
		}
		wing.push_back(row);
	}
	return wing;
}

std::vector<std::vector<Room*>> Labyrinth::merge_wings(const std::vector<std::vector<Room*>>& w1,
	const std::vector<std::vector<Room*>>& w2)
{
	int w1_row = 0, w1_column = 0, w2_row = 0, w2_column = 0;
	pick_room(w1_row, w1_column, w1);
	pick_room(w2_row, w2_column, w2);
	std::vector<std::vector<Room*>> wing;

	//creates a new wing consisting of the two input wings:
	// w1 0
	// 0  w2

	for (int i = 0; i < w1.size() + w2.size(); i++)
	{
		std::vector<Room*> row;
		for (int n = 0; n < w1.size() + w2.size(); n++)
		{
			if (i < w1.size())
			{
				if (n < w1.size())
				{
					row.push_back(w1[i][n]);
				}
				else
				{
					row.push_back(0);
				}
			}
			else
			{
				if (n < w1.size())
				{
					row.push_back(0);
				}
				else
				{
					row.push_back(w2[i - w1.size()][n - w1.size()]);
				}
			}
		}
		wing.push_back(row);
	}
	//connecting the two wings
	//connect the wings
	wing[w1_row][w1.size() + w2_column] = wing[w1.size() + w2_row][w1.size() + w2_column];
	wing[w1_column][w1.size() + w2_row] = wing[w1.size() + w2_column][w1.size() + w2_row];
	wing[w1.size() + w2_row][w1_column] = wing[w1_row][w1_column];
	wing[w1.size() + w2_column][w1_row] = wing[w1_column][w1_row];
	//get rid of the old connections
	wing[w1_row][w1_column] = 0;
	wing[w1_column][w1_row] = 0;
	wing[w1.size() + w2_row][w1.size() + w2_column] = 0;
	wing[w1.size() + w2_column][w1.size() + w2_row] = 0;

	return wing;
}

void Labyrinth::pick_room(int &row, int &column, const std::vector<std::vector<Room*>>& wing)
{
	// Random seed
	std::random_device rd;
	// Initialize Mersenne Twister pseudo-random number generator
	std::mt19937 gen(rd());
	// Generate pseudo-random numbers
	// uniformly distributed in range (0, wing.size() - 1)
	std::uniform_int_distribution<> dis(0, wing.size() - 1);
	//pick row
	row = dis(gen);
	column = dis(gen);
	while (wing[row][column] == 0)
	{
		column = dis(gen);
	}
}

void Labyrinth::print()
{
	for (int i = 0; i < labyrinth.size(); i++)
	{
		for (int n = 0; n < labyrinth.size(); n++)
		{
			if (labyrinth[i][n] != 0)
				std::cout << "* ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
}
