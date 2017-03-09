#include "Linked_List.h"

using namespace N2B;

Linked_List::~Linked_List()
{
	while (root != 0)
	{
		this->consume_first();
	}
}

void Linked_List::add(int key)
{
	if (root == 0)
	{
		Linked_Node *node = new Linked_Node(key);
		root = node;
		return;
	}
	Linked_Node *temp = root;
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	Linked_Node *node = new Linked_Node(key);
	temp->next = node;
}

int Linked_List::consume_first()
{
	int key = root->k;
	Linked_Node *temp = root->next;
	delete root;
	root = temp;
	return key;
}

bool Linked_List::is_empty()
{
	return !root;
}