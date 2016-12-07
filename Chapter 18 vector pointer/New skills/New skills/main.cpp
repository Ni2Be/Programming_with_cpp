#include <iostream>
#include <vector>
#include "Vector.h"
#include "TC.h"

void vec_test();
void consturctor_test();

int main()
{
	consturctor_test();
	//vec_test();
	char ch;
	std::cin >> ch;
}

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
