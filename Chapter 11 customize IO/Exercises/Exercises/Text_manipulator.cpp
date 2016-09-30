#include "Text_manipulator.h"

namespace Text_manipulator {
	
	void txt_to_lower(stringstream& istringStream, string out_txt_name) {
		string ostring;

		char ch;
		while (istringStream.get(ch)) {
			ostring += tolower(ch);
		}
		txt_output(out_txt_name, ostring);
	}

	void txt_oct_hex_search(stringstream& istringStream, string out_txt_name) {
		vector<int> dec;
		vector<int> oct;
		vector<int> hex;

		int temp;
		char ch;

		while (istringStream.get(ch)) 
		{
			if (ch == '0') {
				if (istringStream.peek() == 'x' || istringStream.peek() == 'X')
				{
					istringStream.get();
					if (isxdigit(istringStream.peek())) 
					{
						istringStream >> std::hex >> temp;
						hex.push_back(temp);
					}
				}
				else if (isdigit(istringStream.peek()) && (istringStream.peek() != '0'))
				{
					istringStream >> std::oct >> temp;
					oct.push_back(temp);
				}
			}
			else if (isdigit(ch)) 
			{
				istringStream.unget();
				istringStream >> std::dec >> temp;
				dec.push_back(temp);
			}
		}

		txt_output(out_txt_name, format_Table(dec, oct, hex));
	}

	string format_Table(vector<int> dec, vector<int> oct, vector<int> hex) {
		stringstream output;
		for (int i = 0; i < dec.size(); i++) {
			output << std::dec << dec[i] << "\tdezimal\t\tis " << std::hex << showbase << '\t' << dec[i] << "\tin hexadezimal" << endl;
		}
		for (int i = 0; i < dec.size(); i++) {
			output << std::oct << oct[i] << "\toctal\t\tis " << std::dec << showbase << '\t' << oct[i] << "\tin dezimal" << endl;
		}
		for (int i = 0; i < dec.size(); i++) {
			output << std::hex << hex[i] << "\thexadezimal\tis " << std::dec << showbase << '\t' << hex[i] << "\tin dezimal" << endl;
		}
		return output.str();
	}

	// Input/output
	stringstream data_to_StringStream(string in_txt_name) {
		ifstream istr(in_txt_name.c_str());
		stringstream stringStream;
		if (!istr) error("Text_manipulator::data_to_String", "culd not open " + in_txt_name);
		char ch;
		while (istr.get(ch)) {
			stringStream << ch;
		}
		return stringStream;
	}

	void txt_output(string& out_txt_name, string& ostring) {
		ofstream ostr(out_txt_name.c_str());
		if (!ostr) error("Text_manipulator::txt_output", "culd not open " + out_txt_name);
		for (int i = 0; i < ostring.size(); i++) {
			ostr << ostring[i];
		}
	}
}