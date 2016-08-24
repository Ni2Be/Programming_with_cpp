
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

double difide(int a, int b)
{
	if (b == 0) error("No 0 division!", "main/difide");
	return double(a) / b;
}

void fibonacci()
{
	vector <unsigned int> fibVector(2, 1);
	for (int i = 0; fibVector[i] < fibVector[i] + fibVector[i + 1]; i++)
	{
		fibVector.push_back(fibVector[i] + fibVector[i + 1]);
	}
	for (int i = 0; i < fibVector.size(); i++)
	{
		cout << '\n' << fibVector[i];
	}
	return;
}

vector<int> generateNumbers(int length)
{
	vector<int> randNum;

	srand(time(NULL)); //initialise rand seed by time

	randNum.push_back((rand() % 10) + 1); // fill vector with numbers from 1 to 9
	if (randNum[0] == 10) randNum[0] = 2;
	for (int i = 1; i < length; i++)
	{
		(randNum).push_back(rand() % 10); // fill vector with numbers from 0 to 9
	}
	return randNum;
}

void numberGame(int length)
{

	cout << "NumberGame!\n";

	vector<int> randArray = generateNumbers(length);
	
	int tempGuess = 0;
	int cow = 0;
	int gold = 0;

	do
	{
		cout << "Please insert Number with length of " << length << '\n';
		cin >> tempGuess;
	} while (tempGuess < pow(10, length - 1) || tempGuess >= pow(10, length));


	do
	{

		vector<int> guess;
		guess.push_back(tempGuess / 1000);
		guess.push_back((tempGuess % 1000) / 100);
		guess.push_back((tempGuess % 100) / 10);
		guess.push_back((tempGuess % 10));
		gold = 0;
		cow = 0;

		for (int i = 0; i < length; i++)
		{
			if (guess[i] == randArray[i]) { gold++; }
			for (int j = 0; j < length; j++)
			{
				if (guess[i] == randArray[j]) { cow++; break; }
			}
		}
		cout << cow << "Cows, " << gold << "Gold\n";
		
		if (gold < length)
		{
			do
			{
				cout << "New guess: ";
				cin >> tempGuess;
			} while (tempGuess < pow(10, length - 1) || tempGuess >= pow(10, length));
		}

	} while (gold < length);
	
	cout << "You WON!!!!";

	return;
}


int main()
{
	try
	{
		/*
		int numerator;
		int denuminator;
		cout << "Bitte Zahl eingeben: x / y: ";
		cin >> numerator >> denuminator;
		cout << difide(numerator, denuminator);

		cout << "\nFibonacci:\n";
		fibonacci();
		*/

		const int SIZE = 4;
		numberGame(SIZE);

		keep_window_open();
		return 0;
	}
	catch (exception & e){
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