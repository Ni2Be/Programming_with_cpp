#include <iostream>
#include <iterator>
#include <string>
#include <regex>

void simple_input();

void searching();

int main()
{
	//simple_input();
	searching();
}


void searching()
{
	{
		bool run = true;
		while (run)
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
}

void simple_input()
{
	{
		using namespace std;

		while (true)
		{
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
}