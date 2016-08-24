#pragma once

using namespace std;

// controll elements
const char number = '8';
const char quit = 'q';
const char print = ';';
const char let = 'L';
const char help = 'h';
const char name = 'A';
const string declerationKey = "let"; // user tipes in let, kind will be 'A'


class Token // used to save a number, a variable or an operator
{
public:
	char kind;
	double value;
	string varName;

	Token(char);
	Token(char, double);
	Token(char, string);
};

class TokenStream
{
public:
	TokenStream();
	Token get(); // reads a Token from cin
	void putback(Token); // puts a Token in the buffer
	void ignore(char kind); // ignores all chars till Token kind
	bool isEmpty();
private:
	bool full;
	Token buffer;
};

void cleanUpMess(TokenStream& tokenStream);