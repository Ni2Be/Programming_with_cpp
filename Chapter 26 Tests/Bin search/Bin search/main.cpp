#include <iostream>
#include <vector>
#include <list>

#include "Binsearch.h"

template <class T>
void test(T container, typename T::value_type key = 1000);

int main()
{
	//std::cout << "List<int> test:\n";
	//std::list<int> listi = { -5, -2, 1, 2, 3, 12 };
	//test(listi);

	//std::cout << "\n\nVector<int> test:\n";
	//std::vector<int> veci = { -5, -2, 1, 2, 3, 12 };
	//test(veci);

	//std::cout << "\nList<float> test:\n";
	//std::list<float> listf = { -5.4f, -2.222f, 1.121f, 2.3f, 3.3f, 12.0f };
	//test(listf, -2.222f);

	//std::cout << "\n\nVector<float> test:\n";
	//std::vector<float> vecf = { -5.4f, -2.222f, 1.121f, 2.3f, 3.3f, 12.0f };
	//test(vecf, -2.222f);

	std::cout << "\n\nVector<int> test:\n";
	std::vector<int> vveci = { -5, -2, 1, 2, 3, 12, 23, 34, 45 };

	binary_search_visualized(begin(vveci), end(vveci), -2);
	
	std::cout << "\n\nVector<int> test:\n";
	std::vector<float> vvecf = { -5.4f, -2.222f, 1.121f, 2.3f, 3.3f, 12.0f };

	binary_search_visualized(begin(vvecf), end(vvecf), -2);

	std::cout << "\nEnd\n";
	char ch;
	std::cin >> ch;
}



template <class T>
void test(T container, typename T::value_type key)
{
	using namespace std;
	typename T::value_type search = key;

	if (binary_search_v3(begin(container), end(container), search) != end(container))
		cout << "found " << *(binary_search_v3(begin(container), end(container), search)) << endl;
	else
		cout << "did not find " << search << endl;

	for (typename T::value_type i = -20; i < 20; i++)
	{
		search = i;
		if (binary_search_v3(begin(container), end(container), search) != end(container))
			cout << "found " << *(binary_search_v3(begin(container), end(container), search)) << endl;
		else
			cout << "did not find " << search << endl;
	}
}