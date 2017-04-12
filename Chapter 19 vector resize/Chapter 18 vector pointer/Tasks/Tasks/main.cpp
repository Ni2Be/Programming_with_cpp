#include <iostream>
#include <math.h>
#include <vector>

void f(int[], int);
int factorial(int n);

void fv(std::vector<int>);

const int MAX = 10;
int ga[MAX];

std::vector<int> gv(10);

int main()
{
	//array
	std::cout << "pow i\n";
	for (int i = 0; i < MAX; i++)
	{
		ga[i] = std::pow(2, i);
	}
	f(ga, MAX);
	std::cout << "fac i\n";
	int aa[MAX];
	for (int i = 0; i < MAX; i++)
	{
		aa[i] = factorial(i);
	}
	f(aa, MAX);

	//vector
	std::cout << "vector\npow i\n";
	for (int i = 0; i < gv.size(); i++)
	{
		gv[i] = std::pow(2, i);
	}
	fv(gv);
	std::cout << "fac i\n";
	std::vector<int> lv(MAX);
	for (int i = 0; i < lv.size(); i++)
	{
		lv[i] = factorial(i);
	}
	fv(lv);

	char ch;
	std::cin >> ch;
}

void f(int g[], int size)
{
	int la[MAX];
	for (int i = 0; i < size; i++)
	{
		la[i] = g[i];
		std::cout << la[i] << std::endl;
	}
	int *p = new int[MAX];
	for (int i = 0; i < size; i++)
	{
		p[i] = g[i];
		std::cout << p[i] << std::endl;
	}
	delete[] p;
}

void fv(std::vector<int> in)
{
	std::vector<int> lv(in.size());
	lv = in;
	for each (int i in lv)
	{
		std::cout << i << std::endl;
	}
	std::vector<int> lv2(in);
	for each(int i in lv2)
	{
		std::cout << i << std::endl;
	}
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}