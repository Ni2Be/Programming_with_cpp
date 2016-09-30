#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <sstream>
#include <vector>

#include "error.h"

namespace Text_manipulator
{
	using namespace std;

	void txt_to_lower(stringstream& istringStream, string out_txt_name);

	void txt_oct_hex_search(stringstream& istringStream, string out_txt_name);

	string format_Table(vector<int> dec, vector<int> oct, vector<int> hex);

	// Input/output
	stringstream data_to_StringStream(string in_txt_name);
	void txt_output(string& out_txt_name, string &ostring);
};