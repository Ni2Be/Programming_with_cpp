
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
	throw runtime_error(s1 + "\n" + s2); // first were, second what
}

//stores a number or a operator
class Token 
{
public:
	char kind;
	double value;

	Token(char c)
		:kind(c), value(0) {}

	Token(char c, double d)
		:kind(c), value(d) {}
};

//gets userinput and puts it in to a token
class TokenStream
{
public:
	TokenStream();
	Token get();
	void putback(Token);
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

Token TokenStream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	
	char ch;
	cin >> ch;
	
	switch (ch)
	{
	case ';': case 'q': case '{': case '}': case '!':
	case '(': case ')': case '+': case '-': case '*': case '/': case '%':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
		cin.putback(ch);
		double value;
		cin >> value;
		return Token('8', value); //'8' sign for numbers
	default: 
		error("TokenStream::get()", "Unknowen token");
	}
}

TokenStream tokenStream;

double faku(double d)
{
	if (d == 0) return 1;
	return d * faku(d - 1);
}

/****************************************
* E => T | E+T | E-T					*
* T => P | T*P | T/P					*
* P => z | (E) | {E} | z! | (E)! | {E}!	*
*****************************************/

double expression();
double term();
double primary();

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
	double left = primary();
	Token t = tokenStream.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*': 
			left *= primary();
			t = tokenStream.get();
			break;
		case '/':
			left /= primary();
			t = tokenStream.get();
			break;
		case '%':
			error("::term()", "% not supported");
		default:
			tokenStream.putback(t);
			return left;
		}
	}
}

double primary() {
	Token t = tokenStream.get();
	double d;

	// Fakultätsprüfung
	Token fakToken('0');

	switch (t.kind) 
	{
	case '{':
		d = expression();
		t = tokenStream.get();
		if (t.kind != '}') error("::primary()", "no closing braces ");
		// Fakultätsprüfung
		fakToken = tokenStream.get();
		if (fakToken.kind == '!')
		{
			return faku(d);
		}
		else {
			tokenStream.putback(fakToken);
		}
		return d;
	case '(': 
		d = expression();
		t = tokenStream.get();
		if (t.kind != ')') error("::primary()", "no closing braces ");
		// Fakultätsprüfung
		fakToken = tokenStream.get();
		if (fakToken.kind == '!')
		{
			return faku(d);
		}
		else {
			tokenStream.putback(fakToken);
		}
		return d;
	case '8':
		// Fakultätsprüfung
		fakToken = tokenStream.get();
		if (fakToken.kind == '!')
		{
			return faku(t.value);
		}
		else {
			tokenStream.putback(fakToken);
		}
		return t.value;
	default:
		error("::primary", "not a real function");
	}
}

int main()
{
	try
	{	
		double value = 0;
		while (true)
		{
			Token t = tokenStream.get();
			if (t.kind == 'q') break;
			if (t.kind == ';'){
				cout << '=' << value << '\n';
				continue;
			} else {
				tokenStream.putback(t);
			}
			value = expression();
		}
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