/**
If the program does not work, it is probably becouse of the
random_device, just use an onther random number generator.

@author Jordan
@version 0.2 02/14/17 
*/

#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

namespace N2B
{
	class Actor;

	class Room
	{
		friend class Labyrinth;
		friend class Player;
	public:
		std::string name;
		bool has_hole;
		Actor *actor;
	private:
		Room() {}
		std::vector<Room*> connected_rooms;
	};

	class Actor
	{
		friend class Labyrinth;
		friend class Room;
	public:
		void move(Room* room);
	private:
		std::string what();
		Room *position;
	};

	class Player : public Actor
	{
		friend class Labyrinth;
	private:
		std::string what() { return "Actor"; };
	public:
		bool shoot(std::vector<Room*> shoot_through);
	};

	class Bat : public Actor
	{
		friend class Labyrinth;
	private:
		std::string what() { return "Bat"; };
	};

	class Wumpus : public Actor
	{
		friend class Labyrinth;
	private:
		std::string what() { return "Wumpus"; };
	};

	class Labyrinth
	{
	public:
		std::vector<Room*> get_room_connections(const Room* room);
		Player player;

		explicit Labyrinth(int size, int difficulty);
		~Labyrinth();

		/**
		prints the labyrinths current state to screen

		@param none
		@return none
		*/
		void print();

	private:
		int difficulty;
		Wumpus wump;
		Bat bat;
		std::vector<std::vector<Room*>> labyrinth;
		std::vector<Room*> room_list;
		// Random seed
		std::random_device rd;

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

		/**
		randomly picks rooms that will contain holes, the bat and
		the Wumpus. The player allways starts in room 1.

		@param none
		@return none
		*/
		void prepare_labyrinth();

		void connect_rooms();

		void place_actors();

		void place_holes();
	};

}
