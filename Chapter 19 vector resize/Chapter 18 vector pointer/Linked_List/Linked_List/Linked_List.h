#pragma once

namespace N2B
{
	class Linked_Node
	{
		friend class Linked_List;
	private:
		Linked_Node(int key)
		: k(key) {}
		int k;
		Linked_Node* next;
	};

	class Linked_List
	{
	public:
		Linked_List(){}
		~Linked_List();
		void add(int key);
		int consume_first();
		bool is_empty();
	private:
		Linked_Node* root;
	};
}