#include <iostream>
#include <iomanip>
#include "error.h"

using namespace std;

void keep_window_open() {
	char ch; cin >> ch;
}

struct Birthdate {
	int day;
	int month;
	int year;
	Birthdate(int dd, int mm, int yyyy) :day(dd), month(mm), year(yyyy){}
};

ostream& operator<<(ostream& ostr, Birthdate& date) {
	ostr << date.day << '\t' << date.month << '\t' << date.year;
	return ostr;
}

void hex_oct_out(Birthdate& bday) {
	cout << "hex_oct_out()" << endl << showbase;
	cout << "cout\t" << bday << endl;
	cout << "hex:\t" << hex << bday << endl;
	cout << "oct:\t" << oct << bday << endl;
	cout << "cout\t" << bday << endl;
	cout << noshowbase;
	cout << "dec:\t" << dec << bday << endl;
}

void out_format_test() {
	cout << "out_format_test()" << endl << 1234 << '\t' << 0x4d2 << '\t' << 02322 << endl;
}

void in_format_test() {
	int hexnum;
	cout << "please tap in hex number: ";
	cin >> hex >> hexnum;
	cout << "in dec: " << hexnum;
}

inline ios_base&general(ios_base& b) { //in addition to fixed and scientific
	b.setf(ios_base::fmtflags(0), ios_base::floatfield); //deletes all floating flags
	return b;
}

void floating_out() {
	double val = 1234.567890;
	cout << "floating_out()" << endl;
	cout << "general:\t" << val << endl;
	cout << "fixed:\t\t" << fixed << val << endl;
	cout << "scientific:\t" << scientific << val << endl;
	cout << setprecision(4); //needs <iomanip>
	cout << "setprecision to 4" << endl;
	cout << "general:\t" << general << val << endl;
	cout << "fixed:\t\t" << fixed << val << endl;
	cout << "scientific:\t" << scientific << val << endl;
}

void field() {
	cout << "field" << endl;
	cout << '|' << setw(8) << 1234 << '|' 
		<< setw(10) << 1234 << '|' << setw(5) << 1234 << '|' << endl;
	cout << '|' << setw(8) << 13234 << '|'
		<< setw(10) << 13234 << '|' << setw(5) << 13234 << '|' << endl;
	cout << '|' << setw(8) << 134 << '|'
		<< setw(10) << 134 << '|' << setw(5) << 134 << '|' << endl;
}


int main() {
	try {
		//Birthdate date1(19, 2, 1991);
		//hex_oct_out(date1);
		//out_format_test();
		//in_format_test();
		//floating_out();
		//field();

		keep_window_open();
	}
	catch (exception &e) {
		cerr << e.what();
		keep_window_open();
	}
}