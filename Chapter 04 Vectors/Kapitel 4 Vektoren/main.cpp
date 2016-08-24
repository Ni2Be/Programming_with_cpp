
#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{
	const int SIZE = 10;

	int testArray[SIZE];
	testArray[0] = 1;

	vector<int> testVector(SIZE, 1);
	/*
	for (int i = 0; i < SIZE; i++)
	{
		cout << "\n" << "Array: " << testArray[i] << "\n" <<
			"Vector: " << testVector[i];
	}
	*/
	int tempInt1 = 0;
	int tempInt2 = 0;
	while (cin >> tempInt1 >> tempInt2)
	{
		cout << "\nZahl 1: " << tempInt1 <<
			"\nZahl 2: " << tempInt2;
	}


	testVector.push_back(9);
	testVector[3] = 5; testVector[2] = 4; testVector[8] = 45; testVector[7] = 5;
	sort(testVector.begin(), testVector.end());
	
	for (int i = 0; i < testVector.size(); i++)
	{
		cout << "\nVector[" << i << "]:\t" << testVector[i];
	}

	keep_window_open();
	return 0;
}