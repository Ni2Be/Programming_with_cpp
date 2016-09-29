#include <iostream>
#include <iomanip>
#include "error.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
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

void stringtest() {
	string line;

	cout << "Enter full name: ";
	cin >> line;
	cout << "cout1:" << line << endl;
	getline(cin, line); //flush rest of line

	cout << "Enter full name: ";
	getline(cin, line);
	cout << "cout2:" << line << endl;


	stringstream linestream(line);
	string firstname, lastname;
	linestream >> firstname;
	linestream >> lastname;
	cout << "cout3:" << firstname << "," << lastname;
}

void string_to_oct() {
	string message("https://www.youtube.com/watch?v=DLzxrzFCyOs");
	vector<int> octals;
	int octa;
	string file = "string_to_oct_test.txt";
	ofstream ofi(file.c_str());
	for (int i = 0; i < message.size(); i++) {
		octa = message[i];
		ofi << oct << octa << ' ';
	}
}

void binary_output(string out_txt_name) {
	ofstream ostr(out_txt_name.c_str(), ios_base::binary);
	if (!ostr) error("main::binary_output", "culd not open " + out_txt_name);
	vector<int> outInt = {1,2,3,4,5,6,7,8,9};

	ostr.write((const char*)&outInt[0], sizeof(int) * outInt.size()); //(const char*)&outInt[i] take adress of the curr int and cast it to const char*
}

void binary_data_use(string file_name) {
	fstream fstr(file_name.c_str(), ios::in | ios::out | ios::binary);
	if (!fstr) error("main::binary_data_use", "culd not open " + file_name);

	fstr.seekg(sizeof(int) * 8); // g = get -> reading position [byte1: 0 1 2 3| byte2: 4 5 6 7 ...]
	int i;
	fstr.read((char*)&i, sizeof(int));
	fstr.seekp(sizeof(int)); // p = put -> writing position
	fstr.write((const char*)&i, sizeof(int));
}


int main() {
	try {
		//Birthdate date1(19, 2, 1991);
		//hex_oct_out(date1);
		//out_format_test();
		//in_format_test();
		//floating_out();
		//field();
		//stringtest();
		//string_to_oct();
		binary_output("binary");
		binary_data_use("binary");

		keep_window_open();
	}
	catch (exception &e) {
		cerr << e.what();
		keep_window_open();
	}
}