
#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

void error(string s1, string s2)
{
	throw runtime_error(s1 + "\n" + s2);
}

void fillFibonacci(int x, int y, vector <unsigned int>& fibVector, int n)
{
	fibVector.push_back(x);
	fibVector.push_back(y);

	for (int i = 0; i < n; i++)
	{
		fibVector.push_back(fibVector[i] + fibVector[i + 1]);
	}

	return;
}

void printVector(vector <unsigned int>& vector) {
	for (int i = 0; i < vector.size(); i++)
	{
		cout << '\n' << vector[i];
	}
}

int main()
{
	try
	{
		while (true) {
			int i = 0;
			cout << "\nHow manny?";
			cin >> i;
			vector <unsigned int> fibVector;
			cout << "\nFibonacci:";
			fillFibonacci(1, 1, fibVector, i);
			printVector(fibVector);
		}
		keep_window_open();
		return 0;
	}
	catch (exception & e) {
		cerr << e.what();
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Unknowen Error!";
		keep_window_open();
		return 2;
	}
}