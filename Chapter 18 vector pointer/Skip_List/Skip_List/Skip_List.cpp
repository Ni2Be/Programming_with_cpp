#include "Skip_List.h"

using namespace N2B;

void Skip_List::add(int key)
{
	//list is emty
	if (root == 0)
	{
		root = new Skip_Node(key);
		return;
	}
	//new key is the new root
	if (key < root->key)
	{
		Skip_Node temp(root->key);
		temp.next = root->next;
		root = new Skip_Node(key);
		root->next = temp.next;
		this->add(temp.key);
		return;
	}
	//serche the nodes that will come before the new node
	//level_nodes will contain the nodes that need to point to the
	//new node after the search
	std::vector<Skip_Node*> level_nodes = intern_search(key);
	if (level_nodes[MAXLEVEL - 1]->key == key)
		throw std::runtime_error("\nSkiped_List::add()\nKey is allready in use\n");
	//get the new node into the list
	insert_node(key, level_nodes);
}

int Skip_List::front()
{
	if (root == 0)
		return -1;
	return root->key;
}

void Skip_List::pop_front()
{
	if (root == 0)
		return;
	Skip_Node *temp = root;
	for (int i = 0; i < MAXLEVEL; i++)
	{
		if (root->next[i] != root->next[MAXLEVEL - 1])
		{
			root->next[MAXLEVEL - 1]->next[i] = root->next[i];
		}
		else 
		{
			break;
		}
	}
	root = root->next[MAXLEVEL - 1];
	delete temp;
}

bool Skip_List::is_empty()
{
	return !root;
}

std::vector<Skip_Node*> Skip_List::intern_search(int key)
{
	std::vector<Skip_Node*> level_nodes;
	Skip_Node* curr = root;
	int level = 0;
	while (key > curr->key)
	{
		if ((curr->next[level] != 0) && (key > curr->next[level]->key))
		{
			curr = curr->next[level];
		}
		else if (level == MAXLEVEL - 1)
		{
			level_nodes.push_back(curr);
			return level_nodes;
		}
		else 
		{
			level_nodes.push_back(curr);
			level++;
		}
	}
	throw std::runtime_error("Skiped_List::intern_search\nunknown error");
	return level_nodes;
}

void Skip_List::insert_node(int key, std::vector<Skip_Node*>& level_nodes)
{
	int level = determine_level();
	Skip_Node* prev;
	Skip_Node* next;
	Skip_Node *node = new Skip_Node(key);
	for (level; level < MAXLEVEL; level++)
	{
		prev = level_nodes[level];
		next = prev->next[level];
		prev->next[level] = node;
		node->next[level] = next;
	}
}

void Skip_List::delete_tree()
{
	while (!this->is_empty())
	{
		this->pop_front();
	}
}

int Skip_List::determine_level()
{
	// Random seed
	std::random_device rd;
	// Initialize Mersenne Twister pseudo-random number generator
	std::mt19937 gen(rd());
	// Generate pseudo-random numbers
	// uniformly distributed in range (0, 3)
	std::uniform_int_distribution<> dis(0, 3);

	int level = MAXLEVEL - 1;
	while (level != 0)
	{
		if (dis(gen) == 2)
		{
			break;
		}
		else
		{
			level--;
		}
	}
#ifdef DEBUG
	std::cout << level << std::endl;
#endif // DEBUG

	return level;
}