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

void get_year(Dates::Year& r) {
	string inFile = "test.txt";
	ifstream istr(inFile.c_str());

	istr.exceptions(istr.exceptions() | ios_base::badbit);

	if (!istr) error("::inPut", "Could not open in File");

	if (istr.get() != '{') error("get_year()", "no entrance point {");

	istr >> r;

	if (istr.get() == '|') { cout << "reading completed\n"; }
}

int main() {
	try {
		Dates::Year year1;
		get_year(year1);
		
		
		cout << "year: " << year1.year << endl;
		
		for (int n = 0; n < 12; n++) {
			if (year1.months[n].month != Dates::not_a_month) { cout << "month: " << n + 1 << endl; }
			for (int i = 1; i < 32; i++) {
				for (int j = 0; j < 24; j++) {
					if (year1.months[n].days[i].measuring[j] != Dates::not_a_measuring)
					{
						cout << "day: " << i << ", " << j << "h: " << year1.months[n].days[i].measuring[j] << '\n';
					}
				}
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