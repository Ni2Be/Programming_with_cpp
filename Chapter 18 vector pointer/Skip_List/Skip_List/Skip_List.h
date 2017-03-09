/**
Skip_List.h
Purpose: 
Skip List with the functions to
add: add(int key), get front elem: front() 
and pop front elem: pop_front().

Attention:
the vector that contains the Nodes
goes from 0 to MAXLEVEL - 1
where MAXLEVEL - 1 is the bottem of the list
and 0 is the top:

0				| o - - - - - -
1				| o - - o - - -
[...]			| o - - o - - -
MAXLEVEL - 2	| o - o o - o -
MAXLEVEL - 1	| o o o o o o o

@author Jordan
@version 1.0 03/02/17
*/

#pragma once
#include <vector>
#include <iostream>
#include <math.h>

#include <random>

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

namespace N2B
{

	const int MAXLEVEL = 25;

	class Skip_Node
	{
		friend class Skip_List;
	private:
		Skip_Node(int k)
			:key(k), next(MAXLEVEL) {}

		std::vector<Skip_Node*> next;
		int key;
	};

	class Skip_List
	{
	public:
		Skip_List() {}
		~Skip_List()
		{
			delete_tree();
		}

		/**
		Adds a node to the Skip List.

		@param Key of the new Node
		@return none
		*/
		void add(int key);

		/**
		Returns the key of the root Node.

		@param none
		@return -1 if list is empty, else key of the front node
		*/
		int front();

		/**
		Returns true if the list is empty.

		@param none
		@return true if the list is empty
		*/
		bool is_empty();

		/**
		Pops the root of the list, does nothing if list is empty.

		@param none
		@return none
		*/
		void pop_front();

	private:
		Skip_Node* root;

		/**
		Goes through the list till it findes the new position of
		the searched key. It will store all Nodes that will maybe
		need to point to the new node in the returned vector.

		@param searched key
		@return Node reference
		*/
		std::vector<Skip_Node*> intern_search(int key);

		/**
		Inserts a new node between the nodes in level_nodes
		and their successors

		@param int key of the new node, vector<Skip_Node*>& level_nodes
		@return none
		*/
		void insert_node(int key, std::vector<Skip_Node*>& level_nodes);

		/**
		Goes through every node of the list
		and calls the destructor for each.

		@param none
		@return none
		*/
		void delete_tree();

		/**
		Generates a number that stands for the level
		of a new node.
		The chance to go
		to level 2 is 0.25,
		to level 3 is 0.25²
		and so on.

		@param none
		@return integer 0 to MAXLEVEL - 1
		*/
		int determine_level();
	};
}
