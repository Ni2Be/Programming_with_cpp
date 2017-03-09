#include "Skip_List.h"


void Skip_List::add(int key)
{
	//list is emty
	if (root == 0)
		root = new Skip_Node(key);
	//new key is the new root
	if (key < root->key)
	{
		Skip_Node temp(*root);
		root = new Skip_Node(key);
		root->next = temp.next;
		this->add(temp.key);
	}
	//serche the node that will come before the new node
	//level_nodes will contain the nodes that need to point to the
	//new node after the search
	std::vector<Skip_Node*> level_nodes;
	Skip_Node prePosition = intern_search(key, level_nodes);
	if (prePosition.key == key) 
		throw std::runtime_error("\nSkiped_List::add()\nKey is allready in use\n");

}

bool Skip_List::del(int key)
{
	return false;
}

int Skip_List::search(int key)
{
	return 0;
}

Skip_Node& Skip_List::intern_search(int key, std::vector<Skip_Node*>& level_nodes)
{
	Skip_Node* curr = root;
	int level = 0;
	while (key > curr->key)
	{
		if (key > curr->next[level]->key)
		{
			curr = curr->next[level];
			level = 0;
		}
		else if (level == MAXLEVEL - 1)
		{
			return *curr;
		}
		else 
		{
			level++;
		}
	}
	throw std::runtime_error("Skiped_List::intern_search\nunknown error");
	return *(new Skip_Node());
}

void Skip_List::delete_tree()
{
	
}

int Skip_List::determine_level()
{
	return 1;
}