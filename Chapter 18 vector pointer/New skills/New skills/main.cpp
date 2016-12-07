#include <iostream>
#include <vector>
#include <math.h>
#include "Vector.h"
#include "TC.h"

void vec_test();
void consturctor_test();
void array_test();
void vector_test();

//array_test
const int MAX = 10;
void ArraySqrt(int* tempArray, int size);
void ArrayFak(int* tempArray, int size);
int ga[MAX];
void f(int[], int);
//end array_test

//vector_test
vector<int> gv(10);
void VecSqrt(vector<int>&);
void VecFak(vector<int>&);
void Vf(vector<int>&);
//end vector_test

int main()
{
	//array_test();
	//vector_test();
	//consturctor_test();
	//vec_test();
	char ch;
	std::cin >> ch;
}

//vector_test
void VecSqrt(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = pow(2, i);

	}
}

void VecFak(vector<int> &vec)
{
	for (int n = 1; n <= vec.size(); n++)
	{
		int temp = 1;
		for (int i = 1; i <= n; i++)
		{
			temp *= i;
		}
		vec[n - 1] = temp;
	}
}

void Vf(vector<int> &vec)
{
	vector<int> lv;
	lv = vec;
	for (auto &item : lv)
	{
		cout << item << " ";
	}
	vector<int> lv2(vec);
	for (auto &item : lv2)
	{
		cout << item << " ";
	}

	cout << endl;
}

void vector_test()
{
	cout << "\nvec:\n";
	VecSqrt(gv);
	Vf(gv);
	vector<int> vv(10);
	VecFak(vv);
	Vf(vv);
}
//end vector_test

//array_test
void ArraySqrt(int* tempArray,int size)
{
	for (int i = 0; i < MAX; i++)
	{
		tempArray[i] = pow(2,i);
	}
}

void ArrayFak(int* tempArray, int size)
{
	for (int n = 1; n <= size; n++)
	{
		int temp = 1;
		for (int i = 1; i <= n; i++)
		{
			temp *= i;
		}
		tempArray[n - 1] = temp;
	}
}

void f(int arr[], int size)
{
	int la[MAX];
	for (int i = 0; i < MAX; i++)
	{
		la[i] = arr[i];
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << la[i] << " ";
	}
	int* p = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{
		p[i] = arr[i];
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << p[i] << " ";
	}
	delete(p);
	cout << endl;
}

void array_test()
{
	cout << "\narr:\n";
	ArraySqrt(ga, MAX);
	f(ga, MAX);
	int aa[MAX];
	ArrayFak(aa, MAX);
	f(aa, MAX);
}
//end array_test

void consturctor_test()
{
	CTC loc(4);
	CTC loc2 = loc;
	loc = CTC(5);

	loc2 = copy(loc);
		/*
		CTC copy(CTC a) { return a; };

		00BCF4A4->CTC(CTC&) : -1893360638 (5)
		00BCF570->CTC(CTC&) : -858993460 (5)
		00BCF4A4->~CTC() : 5 (0)
		00BCF6AC->CTC::operator=() : 4 (5)
		00BCF570->~CTC() : 5 (0)
		*/

	loc2 = copy2(loc);
		/*
		CTC copy2(CTC a) { CTC b = a; return b; };

		00BCF4A4->CTC(CTC&) : -1893360638 (5)
		00BCF480->CTC(CTC&) : -858993460 (5)
		00BCF558->CTC(CTC&) : -858993460 (5)
		00BCF480->~CTC() : 5 (0)
		00BCF4A4->~CTC() : 5 (0)
		00BCF6AC->CTC::operator=() : 5 (5)
		00BCF558->~CTC() : 5 (0)
		*/

	cout << endl;

	CTC loc3(6);
	CTC& r = ref_to(loc);
	delete make(7);
	delete make(8);

	cout << endl;

	vector<CTC> v(4);

	cout << endl;

	XX loc4;
	CTC* p = new CTC(9);
	delete p;
	CTC* pp = new CTC[5];
	delete[] pp;
}

void vec_test()
{
	const int SIZE = 10;
	not_std::vector vec0(SIZE);
	not_std::vector vec1(SIZE / 2);
	for (int i = 0; i < SIZE; i++)
	{
		vec0[i] = i;
		if (i < SIZE / 2)
			vec1[i] = i * i;
	}
	not_std::vector vec2 = vec0;//same as: not_std::vector vec2(vec);
	vec0[3] = 10;

	for (int i = 0; i < SIZE / 2; i++)
	{
		std::cout << vec1[i] << ", ";
	}
	std::cout << "\n";
	vec1 = vec2;
	vec1 = vec1;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << vec1[i] << ", ";
	}
	std::cout << "\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << vec0[i] << ", ";
	}
	std::cout << "\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << vec2[i] << ", ";
	}
}
