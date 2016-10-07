#include "Translator.h"

namespace Translator {

	string string_to_hex(string m)
	{
		string message = m;
		vector<int> octals;
		int hexa;
		stringstream ss;
		for (int i = 0; i < message.size(); i++) {
			hexa = message[i];
			ss << hex << hexa << ' ';
		}
		return ss.str();
	}

	string hex_to_string(string m)
	{
		string message;
		int ch;
		stringstream ss(m);
		while (ss >> hex >> ch)
		{
			message += (char)ch;
		}
		return message;
	}
}