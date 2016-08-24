#include "Date.h"
#include <iostream>

using namespace std;
using namespace Calendar;

void keepWindowOpen() {
	char ch;
	cin >> ch;
}

int main() {
	try {
		Date datum(10, Date::feb, 2016);
		for (int i = 0; i < 40; i++) {
			cout << datum << "\n";
			datum.addDay(14);
		}
		Date datum2(31, Date::jan, 2016);
		datum2.addMonth(3);
		cout << datum2 << "\n";

		Date datum3;

		cin >> datum3;

		cout << datum3;

		cin.clear();
		keepWindowOpen();
	}
	catch (runtime_error& e) {
		cerr << e.what();
		keepWindowOpen();
	}
}
