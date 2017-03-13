#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <iterator>

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG


class Room
{
	bool has_hole;
	bool wumpus_inside;
	bool bat_inside;
};

class Bat
{
	Room *position;
};

class Wumpus
{
	Room *position;
	bool is_awake;
};

class Labyrinth
{
public:
	explicit Labyrinth(int size);
	~Labyrinth();

	/**
	prints the labyrinths current state to screen

	@param none
	@return none
	*/
	void print();

private:
	Wumpus wump;
	Bat bat;
	std::vector<std::vector<Room*>> labyrinth;

	/**
	generates 4 new rooms connected with each other 
	represented by a vector<vector> of pointers like:
	0 * * *
	* 0 * *
	* * 0 *
	* * * 0

	@param none
	@return a new wing of 4 rooms connected with each other
	*/
	std::vector<std::vector<Room*>> generate_wing();

	/**
	merges two wings to one by randomly picking two rooms of wing, 
	two rooms of wing two and coonect them:
	input:
	w1
	0 * * *
	* 0 * *
	* * 0 *
	* * * 0
	w2
	0 * * *
	* 0 * 0
	* * 0 *
	* 0 * 0

	possible output (w1 picked rooms 1 and 4, w2 picked rooms 2 and 4):
	0 * * 0 0 * 0 0
	* 0 * * 0 0 0 0
	* * 0 * 0 0 0 0
	0 * * 0 0 0 0 *
	0 0 0 0 0 * * *
	* 0 0 0 * 0 * 0
	0 0 0 0 * * 0 *
	0 0 0 * * 0 * 0

	@param two wings
	@return a new wing consisting of the two input wings connected with each other
	*/
	std::vector<std::vector<Room*>> merge_wings(const std::vector<std::vector<Room*>>& w1, 
													const std::vector<std::vector<Room*>>& w2);

	/**
	randomly picks two rooms of wing that are connected:
	input:
	wing
	0 1 2 3
	0 * * * 0
	* 0 * * 1
	* * 0 * 2
	* * * 0 3

	possible out come:
	row = 2
	column = 1
	would mean: room 2 and 3

	@param two int references that will contain the out come and the wing
	@return none
	*/
	void pick_room(int &row, int &column, const std::vector<std::vector<Room*>>& wing);



};

