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

void outPut(vector<int>& vec) {
	string outFile = "test.txt";
	ofstream ostr(outFile.c_str());
	if (!ostr) error("::outPut", "Could not open out File");
	for (int i = 0; i < vec.size(); i++) {
		ostr << vec[i] << '\n';
		//if (i == 18) ostr << "dfsdfsdfg"; // Test fail
	}
}

void inPut(vector<int>& vec) {
	string inFile = "test.txt";
	ifstream istr(inFile.c_str());

	istr.exceptions(istr.exceptions() | ios_base::badbit); 

	if (!istr) error("::inPut", "Could not open in File");

	//istr.clear(ios_base::badbit); // test
	
	int tempNum;
	while(istr >> tempNum){
		vec.push_back(tempNum);
	}
	if (istr.eof()) { return; }

	if (istr.fail()) {
		istr.clear();
		char temp;
		temp = istr.peek();
		if (temp != EOF) {
			istr.clear(ios_base::failbit);
		}
	}
}

int main() {
	try {
		vector<int> numbers;

		for (int i = 0; i < 200; i++) {
			numbers.push_back(i);
		}

		outPut(numbers);

		vector<int> newNumbers;

		inPut(newNumbers);

		for (int i = 0; i < newNumbers.size(); i++) {
			cout << newNumbers[i] << "\n";
		}

		cout << "END";
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