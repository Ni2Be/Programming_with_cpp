#include <iostream>

#include "Vector.h"

void vec_test();

struct Test {
	int i;
	double f;
	Test() :i(2), f(7){}
};

int main()
{
	vec_test();
	char ch;
	std::cin >> ch;
}

void vec_test()
{
	
	not_std::vector<int> v1;
	v1.push_back(1);
	v1[0] = 4;
	v1.push_back(9);
	std::cout << v1[0] << " " << v1[1];
}