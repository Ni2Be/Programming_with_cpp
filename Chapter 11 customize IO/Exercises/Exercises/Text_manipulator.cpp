#include "Text_manipulator.h"

namespace Text_manipulator {
	
	void txt_to_lower(string in_txt_name, string out_txt_name) {
		ifstream istr(in_txt_name.c_str());
		string ostring;

		if (!istr) error("Text_manipulator::txt_to_lower", "culd not open " + in_txt_name);
		char ch;
		while (istr) {
			istr >> ch;
			ostring += tolower(ch);
		}
		txt_output(out_txt_name, ostring);
	}

	/*
	stringstream& data_to_String(string in_txt_name) {
		ifstream istr(in_txt_name.c_str());
		stringstream ostringStream;
		if (!istr) error("Text_manipulator::txt_to_lower", "culd not open " + in_txt_name);
		char ch;
		while (istr) {
			istr >> ch;
			ostringStream << tolower(ch);
		}
		return ostringStream;
	}
	*/

	void txt_output(string& out_txt_name, string& ostring) {
		ofstream ostr(out_txt_name.c_str());

		if (!ostr) error("Text_manipulator::txt_output", "culd not open " + out_txt_name);
		cout << ostring.size() << endl;
		for (int i = 0; i < ostring.size(); i++) {
			cout << i << endl;
			ostr << ostring[i];
		}
		cout << "33";
	}
}