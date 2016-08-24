/*
*			Calculator
*
*	First version: 
*	07.27.2016
*	by Jordan Scholzen (github: Nice2Bee)
*	
*	simple calculator
*	gets user in-/output by cin/cout
*
*	Commands:
*	Print:	';'
*	Quit:	'q'
*	Allowed mathematical operators: '+', '-', '*', '/', '(', ')', '{', '}', '%'
*
*	-------------------------------------------------------------------------
*	Grammar:
*	Terminals:		{z,+,-,*,/,!,%,(,),{,}}, (z € 0,1,2,3,4,5,6,7,8,9)
*	Nonterminals:	{S,E,T,F,P}
*
*	*****************************************
*	* S => E;| E;S							*
*	* E => T | E+T | E-T					*
*	* T => F | T*F | T/F | T%F				*
*	* F => P | P!							*
*	* P => z | +z | -z	| (E) | {E} 		*
*	*****************************************
*	Funktionnames:	S = start userinput seperated by ';'
*					E = expression()
*					T = term() 
*					F = isFacto()
*					P = primary()
*	-------------------------------------------------------------------------
*
*
*
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open();
void error(string s1, string s2);
void cleanUpMess();

double facto(double d);

double expression();
double term();
double isFacto();
double primary();

inline void keep_window_open() { char ch; cin >> ch; }

void error(string s1, string s2) // first: where, second: what
{
	//throw runtime_error(s1 + "\n" + s2 + "\n"); // only to locate bugs
	throw runtime_error(s2 + "\n");
}

const char number = '8';
const char quit = 'q';
const char print = ';';

class Token // used to save a number or an operator
{
public:
	char kind;
	double value;

	Token(char c)
		:kind(c), value(0) {}

	Token(char c, double d)
		:kind(c), value(d) {}
};

class TokenStream
{
public:
	TokenStream();
	Token get(); // reads a Token from cin
	void putback(Token); // puts a Token in the buffer
	void ignore(char c); // ignores all chars till c
private:
	bool full;
	Token buffer;
};

TokenStream::TokenStream()
	:full(false), buffer(0) {}

void TokenStream::putback(Token token)
{
	if (full) error("TokenStream::putback()", "buffer full");
	full = true;
	buffer = token;
}

Token TokenStream::get() // reads cin and puts it in a token
{
	if (full) // prooves if there is a token ready
	{
		full = false;
		return buffer;
	}

	char ch;		//will not read whitespace
	cin >> ch;

	switch (ch)
	{
	case print: 
	case quit: 
	case '{': 
	case '}': 
	case '!':
	case '(': 
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/': 
	case '%':
		return Token(ch); // every char represents himselfe
	case '.':			// a decimal number can start with a '.'
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9':
		cin.putback(ch); // every number will be read as double
		double value;
		cin >> value;
		return Token(number, value);
	default:
		error("TokenStream::get()", "Unknowen token");
	}
}

void TokenStream::ignore(char c) 
{
	if (full && (c == buffer.kind)) {
		full = false;
		return;
	}
	full = false;
	char temp = 0;
	while (cin >> temp) {
		if(temp == c) return;
	}
	return;
}

TokenStream tokenStream; //tokenStream used in calculator()

void cleanUpMess() {
	tokenStream.ignore(print); // ignores till next ';' (print)
}

double facto(double d) //calculates factorial
{
	if (d == 0) return 1;
	return d * facto(d - 1);
}

double expression() {
	double left = term();
	Token t = tokenStream.get();
	while (true) {
		switch (t.kind)
		{
		case '+':
			left += term();
			t = tokenStream.get();
			break;
		case '-':
			left -= term();
			t = tokenStream.get();
			break;
		default:
			tokenStream.putback(t);
			return left;
		}
	}
}

double term() {
	double left = isFacto();
	Token t = tokenStream.get();
	double rigth;
	int moduloTest1;
	int moduloTest2;
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= isFacto();
			t = tokenStream.get();
			break;
		case '/':
			rigth = isFacto();
			if (rigth == 0) error("::term()", "No 0 division!");
			left /= rigth;
			t = tokenStream.get();
			break;
		case '%':
			moduloTest1 = int(left);
			rigth = isFacto();
			moduloTest2 = int(rigth);
			if (moduloTest1 != left || moduloTest2 != rigth) 
				error("::term()", "Modulo not defined for decimal numbers");
			if (rigth == 0) error("::term()", "No 0 division!");
			return moduloTest1 % moduloTest2;
		default:
			tokenStream.putback(t);
			return left;
		}
	}
}

double isFacto() {
	double left = primary();
	Token t = tokenStream.get();
	while (true)
	{
		switch (t.kind)
		{
		case '!':
			left = facto(left);
			t = tokenStream.get();
			break;
		default:
			tokenStream.putback(t);
			return left;
		}
	}
}

double primary() {
	Token t = tokenStream.get();
	double d;

	switch (t.kind)
	{
	case number:
		return t.value;
	case '{':
		d = expression();
		t = tokenStream.get();
		if (t.kind != '}') error("::primary()", "no closing braces ");
		return d;
	case '(':
		d = expression();
		t = tokenStream.get();
		if (t.kind != ')') error("::primary()", "no closing braces ");
		return d;
	case '-' :				// allows numbers to start with - or +
		return -primary();
	case '+' :
		return primary();
	default:
		error("::primary", "not a real function");
	}
}

void calculate() {
	
	double value = 0;
	while (true)
	{
		try
		{
			Token t = tokenStream.get(); //reads first token from cin
			if (t.kind == quit) break;
			if (t.kind == print) {
				cout << '=' << value << '\n';
				while (t.kind == print) t = tokenStream.get(); // eats multiple ';' (print)
				tokenStream.putback(t);
				continue;
			}
			else {
				tokenStream.putback(t);
			}
			value = expression();
		}
		catch (exception & e)
		{
			cerr << e.what();
			cleanUpMess();
		}
	}
	
}

int main()
{
	try
	{
		calculate();
		cout << "See you!";
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