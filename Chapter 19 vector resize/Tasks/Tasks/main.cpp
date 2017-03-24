#include <iostream>

#include "Template.h"

int main()
{
	N2B::S<int> t1(1);
	N2B::S<double> t2(2.0);
	N2B::S<char> t3('3');
	N2B::S<N2B::S<int>> t4(N2B::S<int> (4));

	std::cout << "test 1: " << t1.get() << std::endl;
	std::cout << "test 2: " << t2.get() << std::endl;
	std::cout << "test 3: " << t3.get() << std::endl;
	std::cout << "test 4: " << t4.get().get() << std::endl;
	
	std::cout << "change val: ";
	std::cin >> t1 >> t2 >> t3 >> t4;

	std::cout << "test 5: " << t1 << std::endl;
	std::cout << "test 6: " << t2 << std::endl;
	std::cout << "test 7: " << t3 << std::endl;
	std::cout << "test 8: " << t4 << std::endl;

	char ch;
	std::cin >> ch;
}