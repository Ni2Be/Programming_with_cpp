#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Error.h"
#include "Reading.h"
#include "Day.h"
#include "Month.h"
#include "Year.h"

using namespace std;

void get_month(Dates::Month& r) {
	string inFile = "test.txt";
	ifstream istr(inFile.c_str());

	istr.exceptions(istr.exceptions() | ios_base::badbit);

	if (!istr) error("::inPut", "Could not open in File");

	istr >> r;

	if (istr.get() == '|') { cout << "reading completed\n"; }
}

int main() {
	try {
		Dates::Month month1;
		get_month(month1);
		
		cout << "month: " << month1.month << endl;
		
		for (int i = 1; i < 32; i++) {
			for (int j = 0; j < 24; j++) {
				if (month1.days[i].measuring[j] != Dates::not_a_measuring) 
					{ cout << "day: " << i << ", " << j << "h: " << month1.days[i].measuring[j] << '\n'; }
			}
		}

		cout << "\nEND";
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