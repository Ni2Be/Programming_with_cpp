#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctype.h>

#include "token.h"
#include "error.h"

using namespace std;

// Classes Token, Tokenstream:
Token::Token(char c)
	:kind(c), value(0) {}

Token::Token(char c, double d)
	:kind(c), value(d) {}

Token::Token(char c, string s)
	:kind(c), varName(s) {}


// Functions working with Tokens:
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
	//(isspace(cin.get()) ? cin.putback(print) : cin.unget()); // enter and space will print
	char ch;
	cin >> ch;

	switch (ch)
	{
	case help:
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
	case '=':
		return Token(ch); // every char represents himselfe
	case '.':			// a decimal number can start with a '.'
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		cin.putback(ch); // every number will be read as double
		double value;
		cin >> value;
		return Token(number, value);
	default:
		if (isalpha(ch)) // proofing if there is a "let" decleration or variable name
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
				s += ch;
			}
			cin.putback(ch);
			if (s == declerationKey) {
				return Token(let);
			}
			Token t(name, s);
			return t;
		}
		error("TokenStream::get()", "Unknowen token");
	}
}

void TokenStream::ignore(char kind) // clears up all userinput till Token kind
{
	cin.putback(print); // to make sure the whole input has an end
	if (full && (kind == buffer.kind)) {
		full = false;
		return;
	}
	full = false;
	char temp = 0;
	while (cin >> temp) {
		if (temp == kind) return;
	}
	return;
}

bool TokenStream::isEmpty() {
	return !full;
}

void cleanUpMess(TokenStream& tokenStream) {
	tokenStream.ignore(print); // ignores till next ';' (print)
}
