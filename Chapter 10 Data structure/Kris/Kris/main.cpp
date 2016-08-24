#include <stdlib.h>
#include <string>
#include <vector>

#include <iostream>
#include <fstream>

using namespace std;

void error(string s1, string s2) // first: where, second: what
{
	throw runtime_error(s1 + "\n" + s2 + "\n"); // only to locate bugs
												//throw runtime_error(s2 + "\n");
}

void outPut(string kris) {
	unsigned long int i = 0;
	while (i < true) {
		string outFile = "Kris" + to_string(i++) + ".txt";
		cout << outFile << "\n";
		ofstream ostr(outFile.c_str());
		if (!ostr) error("::outPut", "Could not open out File");
		ostr << kris;
	}
}

int main() {
	try {
		string kris = "hi Kris";

		outPut(kris);
		
		char ch;
		cin >> ch;
	}
	catch (exception &e) {
		cerr << e.what();
		char ch;
		cin >> ch;
	}
	catch (...) {
		cerr << "Unknowen Error";
		char ch;
		cin >> ch;
	}
}