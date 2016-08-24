
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() 
{
	cout << "Quit: y\n"; 
	char ch;
	do 
	{ 
		cin >> ch;
	} while (ch != 'y');
}

int main()
{
	cout << "Bitte geben Sie Ihren Namen: ";
	string firstname;
	cin >> firstname;
	cout << "Hallo " << firstname << "\n";
	
	int i = 8;//1000
	int i1 = 2;//0010
				//1010 = 10
	i = 0;
	while (cin >> firstname && i < 5) 
	{
		cout << i;
		i++;
	}
	cout << i;
	cout << "i = " << i << ", i1 = " << i1 << "\n";
	i = i ^ i1;
	i1 = i ^ i1;
	i = i ^ i1;
	cout << "i = " << i << ", i1 = " << i1 << "\n";
	keep_window_open();
	return 0;
}