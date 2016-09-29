#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Text_manipulator.h"

using namespace std;

void keep_window_open() {
	char ch; cin >> ch;
}



int main() {
	try {
		//Text_manipulator::txt_to_lower(Text_manipulator::data_to_StringStream("input.txt"), "output.txt");
		//string programString = "Here, I'm a String!";
		//stringstream ss(programString);
		//Text_manipulator::txt_to_lower(ss, "output2.txt");
		Text_manipulator::txt_oct_hex_search(Text_manipulator::data_to_StringStream("hexOct.txt"), "dec.txt");

		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << e.what();
		keep_window_open();
	}
}