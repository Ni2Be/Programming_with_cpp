/**
Skip_List.h
Purpose: 
Skip List with the functions to
add: add(int key), delete: del(int key) 
and search: search(int key).

@author Jordan
@version 0.1 03/02/17
*/

#pragma once
#include <vector>
#include <iostream>

class Skip_Node
{
	friend class Skip_List;
private:
	Skip_Node()
		:key(), next() {}
	Skip_Node(int k)
		:key(k), next() {}
	Skip_Node(Skip_Node& node)
		:key(node.key), next(node.next) {}

	std::vector<Skip_Node*> next;
	int key;
};

class Skip_List
{
public:
	Skip_List()
	:root(0) {}
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
	Searches a node by his key and deletes it.

	@param searched key
	@return true if a node was deleted, 
	false if no node was found. 
	*/
	bool del(int key);
	
	/**
	Searches a node by his key.

	@param searched key
	@return -1 if no Node was found, else key of the searched node
	*/
	int search(int key);
private:
	const int MAXLEVEL = 25;
	Skip_Node* root;

	/**
	Goes through the list till it findes the searched key
	and returns the Node reference or the node to its left 
	if there is no node with the searchd key.

	@param searched key
	@return Node reference
	*/
	Skip_Node& intern_search(int key, std::vector<Skip_Node*>&);
	
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
	@return integer 1 to MAXLEVEL
	*/
	int determine_level(); 
};
