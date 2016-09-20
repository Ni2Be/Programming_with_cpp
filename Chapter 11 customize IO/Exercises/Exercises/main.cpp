#include "Text_manipulator.h"

using namespace std;

void keep_window_open() {
	char ch; cin >> ch;
}

int main() {
	try {
		Text_manipulator::txt_to_lower("input.txt", "output.txt");

		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << e.what();
		keep_window_open();
	}
}