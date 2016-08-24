#include <stdlib.h>
#include <iostream>

namespace X {
	void print() {
		std::cout << "Hallo X\n";
	}
}

namespace Y {
	void print() {
		std::cout << "Hallo Y\n";
	}
}

namespace Z {
	void print() {
		std::cout << "Hallo Z\n";
	}
}

int main() {
	X::print();
	Y::print();
	Z::print();

	{
		std::cout << "Using Z::print\n";
		using Z::print;
		print();
	}

	{
		std::cout << "Using namespace Y\n";
		using namespace Y;
		print();
	}

	char ch;
	std::cin >> ch;

	return 0;
}