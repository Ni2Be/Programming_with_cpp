#include "error.h"

using namespace std;

void error(string s1, string s2) // first: where, second: what
{
	//throw runtime_error(s1 + "\n" + s2 + "\n"); // only to locate bugs
	throw runtime_error(s2 + "\n");
}