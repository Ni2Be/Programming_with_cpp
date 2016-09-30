#include <iostream>
#include <vector>
#include <string>

#include <Audioclient.h>

using namespace std;

void error(string where, string what) {
	throw runtime_error(where + '\n' + what);
}

void keep_window_open() {
	char c; cin >> c;
}

inline ios_base& general(ios_base& b) {
	b.setf(ios_base::fmtflags(0), ios_base::floatfield);
	return b;
}

void test_output() {
	int birth_year = 1990;
	cout << showbase;
	cout << "hexadecimal:\t" << hex << birth_year << endl;
	cout << "age: \t\t" << abs(birth_year - 2016) << endl;
	cout << "octal:\t\t" << oct << birth_year << endl;
	cout << "age: \t\t" << abs(birth_year - 2016) << endl;
	cout << "decimal:\t" << dec << birth_year << endl;
	cout << "age: \t\t" << abs(birth_year - 2016) << endl;

	/*
	int a, b, c, d;
	cout << "\nPlease enter 4 numbers:" << endl;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
	*/

	double decimalnumber = 1234567.89;
	cout << decimalnumber << endl << fixed << decimalnumber << endl
		<< scientific << decimalnumber << endl << general << decimalnumber << endl;
}

void table_test() {
	vector<string> names;
	vector<string> lastnames;
	vector<int> numbers;
	vector<string> mail;

	for (int i = 10; i <= 10000; i *= i) {
		names.push_back("name" + to_string(i));
		cout << i << endl;
	}
	for (int i = 0; i < names.size(); i++) {
		cout << "i: " << names[i] << endl;
	}
}

int main() {
	try {
		//test_output();
		table_test();
		IAudioClient::Initialize;
		IAudioClient::GetService;
		IAudioClient::Start;


		keep_window_open();
	} catch(exception& e) {
		cerr << e.what();
		keep_window_open();
	}
}