#include <bitset>
#include <cstdint>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

void Lychrel();

enum Flag {
	ONE = 1,
	TWO = 1 << 1,
	THREE = 1 << 2,
	FOUR = 1 << 3,
	FIVE = 1 << 4,
	SIX = 1 << 5
};
void set_flag(Flag f);
inline Flag operator|(Flag a, Flag b);


void decipher(const unsigned long* const v, unsigned long* const w, const unsigned long* const k);

void decry();

using namespace std;
int main()
{
	
	/*
	bitset<8> a(9);
	bitset<8> b(3);
	bitset<8> c(a ^ b);
	cout << a << endl << b << endl << c;

	string s("01110111");
	bitset<8> st(s);
	cout << endl << st << endl << (st ^ c);


	int var = a.to_ulong();
	cout << "var: " << var;
	//Lychrel();
	*/
	//set_flag(ONE | THREE | FOUR);
	unsigned int people = 42949672910;

	int ave = 0;

	for (char c = -128; c < 127; c++)
		cout << c << endl;


	for (int i = 0; i < people; i++)
	{
		ave += 23;
	}
	ave /= people;
	cout << ave;
	cout << "quit: ";
	char ch;
	cin >> ch;
}




inline Flag operator|(Flag a, Flag b)
{
	return static_cast<Flag>(static_cast<int>(a) | static_cast<int>(b));
}

void set_flag(Flag f)
{
	/*
	bitset<6> bs(f);
	cout << bs << endl;
	if (bs[0])
		cout << "ONE!" << endl;
	if (bs[1])
		cout << "TWO!" << endl;
	if (bs[2])
		cout << "THREE!" << endl;
	if (bs[3])
		cout << "FOUR!" << endl;
	if (bs[4])
		cout << "FIVE!" << endl;
	if (bs[5])
		cout << "SIX!" << endl;
	*/

	if (ONE & f)
		cout << "ONE!" << endl;
	if (TWO & f)
		cout << "TWO!" << endl;
	if (THREE & f)
		cout << "THREE!" << endl;
	if (FOUR & f)
		cout << "FOUR!" << endl;
	if (FIVE & f)
		cout << "FIVE!" << endl;
	if (SIX & f)
		cout << "SIX!" << endl;
}




bool is_pal(string i)
{
	for (int n = 0, p = i.length() - 1; n < i.length(); n++, p--)
	{
		if (i[n] != i[p])
			return false;
	}
	return true;
}

void Lychrel()
{
	while (1)
	{
		try
		{
			string N;
			cin >> N;

			while (!is_pal(N))
			{
				cout << N << endl;
				string n = N;
				reverse(begin(n), end(n));
				N = to_string(stoll(N) + stoll(n));
			}
			cout << N;
		}
		catch (exception &e)
		{
			cerr << e.what() << endl;
		}
	}

}