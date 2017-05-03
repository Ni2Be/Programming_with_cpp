#include <iostream>
#include <iterator>
#include <string>
#include <regex>




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <iomanip>

void simple_input();

void searching();
std::regex get_pattern();

int main()
{
	//simple_input();
	//searching();

	/*
	std::regex r{ "()" };
	std::string g = "sdfh()sdfkjhl";
	if (std::regex_search(g, r)) std::cout << "match";
	*/
	using namespace std;


	tm t = {};
	locale l("");
	cin.imbue(locale(l));
	cin >> get_time(&t, "%H:%M");

	cout << put_time(&t, "%M") << put_time(&t, "%M") << endl;


	char ch;
	std::cin >> ch;
}


void searching()
{
	bool run = true;
	while (run)
	{
		using namespace std;
		
		regex pattern = get_pattern();

		cout << "search in: ";
		string line;
		while (getline(cin, line))
		{
			if (line == "q}")
			{
				exit(0);
			}
			else if (line == "n}")
			{
				break;
			}
			smatch matching;

			/*example:
			input:
			regex = \([^)]*\)
			input:
			line1 = (hello)
			line2 = (hello)world

			output:
			regex_match(line1) == true
			regex_match(line2) == false
			regex_search(line1) == true
			regex_search(line2) == true
			*/
			if (regex_search(line, matching, pattern))
			{
				for (int i = 0; i < matching.size(); i++)
				{
					cout << i << " " << matching[i] << endl;
				}
			}
			else
			{
				cout << "nothing found\n";
			}
		}
	}
}

std::regex get_pattern()
{
	using namespace std;

	regex pattern;
	bool is_valid = false;

	cout << "q} to quit\nn} for new pattern\n";
	while (!is_valid)
	{
		cout << "search pattern: ";
		string input;
		getline(cin, input);

		if (input == "q}")
		{
			exit(0);
		}
		//regex operator=() throws
		try
		{
			pattern = input;
			is_valid = true;
		}
		catch (exception)
		{
			cerr << input << " nope!\n";
		}
	}
	return pattern;
}


void simple_input()
{
	while (true)
	{
		using namespace std;

		string s;
		cout << "Input: ";
		cin >> s;

		if (s == "q")
			break;

		/*valid:
		any number of letters, 3 digits,
		any number of letters or digits
		*/
		regex valid{ "[[:alpha:]]*\\d{3}\\w*" };
		if (regex_match(s, valid))
			cout << s << " is valid\n";
		else
			cout << s << " is invalid\n";
	}
}