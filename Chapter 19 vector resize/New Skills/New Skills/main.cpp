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
	not_std::vector<int> v2;
	not_std::vector<int> v1;
	v1.push_back(1);
	v1[0] = 4;
	v1.push_back(9);
	v2 = v1;
	std::cout << v2[0] << " " << v2[1];
}