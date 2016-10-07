
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
/*	cout << "Bitte geben Sie Ihren Namen: ";
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
	*/
	while (1) {
		long long x, i, p;
		cin >> p;
		long long isprime = 0;

		for (x = 0; x <= p; x++)
		{
			for (i = 2; i < x; i++)
			{
				if (x%i == 0) break;
			}
			if (i == x) isprime++;
		}
		long double log1 = p / log(p);
		//long long log1 = p / ((p - 1) * 1 - 1 / 2 * pow((p - 1), 2.0) + 1 / 3 * pow((p - 1), 3.0) - 1 / 4 * pow((p - 1), 4.0));
		cout << "real: " << isprime << " ln: "<< log1 << " in %: " << log1 / isprime * 100 << endl;
	}
	keep_window_open();
	return 0;
}