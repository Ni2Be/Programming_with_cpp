#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

const string filename = "numbers.txt";

void error(string function, string failur) {
	throw runtime_error(function + '\n' + failur);
}

void checkFile(string functionCalling, int checknumber) {
	// goodbit == 0, eofbit == 1, failbit == 2, badbit == 4
	if (checknumber == 2) { error(functionCalling, "failbit"); }
	if (checknumber == 4) { error(functionCalling, "badbit"); }
}

void fillNumbers(vector<double>& numVec) {
	ifstream istr(filename);
	double tempDouble;
	while (istr.peek() != '|' && istr >> tempDouble) {
		numVec.push_back(tempDouble);
	}
	checkFile("fillNumbers()", istr.rdstate());
}

double vecSum(vector<double>& numVec) {
	double result = 0;
	for (int i = 0; i < numVec.size(); i++) {
		result += numVec[i];
	}
	return result;
}

int main() {
	try {
		vector<double> numbers;
		fillNumbers(numbers);
		cout << vecSum(numbers);
	}
	catch (exception& e) {
		cerr << e.what();
	}

	char ch;
	cin >> ch;
}