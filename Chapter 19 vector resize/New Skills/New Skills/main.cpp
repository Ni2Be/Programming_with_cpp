#include <iostream>

#include "Vector.h"

void vec_test();

using namespace std;

struct test {
	int i;
	double f;
	test() :i(2), f(7){}
};

int main()
{
	vec_test();
	char ch;
	cin >> ch;
}

void vec_test()
{
	not_std::vector<double> vec0(10);
	for (int i = 0; i < vec0.size(); i++)
	{
		cout << vec0[i] << " ";
	}

	cout << endl;
	vec0.resize(20, 5);

	for (int i = 0; i < vec0.size(); i++)
	{
		cout << vec0[i] << " ";
	}

	cout << endl;
	vec0.push_back(20);

	for (int i = 0; i < vec0.size(); i++)
	{
		cout << vec0[i] << " ";
	}
}