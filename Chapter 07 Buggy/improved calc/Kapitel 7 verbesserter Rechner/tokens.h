#pragma once
// Classes Token, Tokenstream:
class Token // used to save a number, a variable or an operator
{
public:
	char kind;
	double value;
	string varName;

	Token(char c)
		:kind(c), value(0) {}

	Token(char c, double d)
		:kind(c), value(d) {}

	Token(char c, string s)
		:kind(c), varName(s) {}
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