/*
#TODO
will implement streamstrings to handle whitespace
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <sstream>

#include "error.h"

namespace Text_manipulator
{
	using namespace std;
	void txt_to_lower(string in_txt_name, string out_txt_name);
	void txt_output(string& out_txt_name, string &ostring);
};