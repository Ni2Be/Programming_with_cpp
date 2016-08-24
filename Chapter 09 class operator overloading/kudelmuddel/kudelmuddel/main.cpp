#include <iostream>

void keepWindowOpen() {
	char ch;
	std::cin >> ch;
}

struct X {
	void outf(int x) 
	{
		if (x == 1) return; // added
		struct Y 
		{
			int innerf() 
			{
				return 1;
			}
			int m;
		};
		int m;
		m = x;
		Y m2;
		return outf(m2.innerf());
	}

	int m;

	void g(int m) {
		if (m) {
			outf(m + 2);
		}
		else {
			g(m + 2);
		}
	}

	X() {}

	void m3() {}
};

void main() { // now out of struct X
	X a;
	a.outf(2);
	std::cout << a.m;
	keepWindowOpen();
}