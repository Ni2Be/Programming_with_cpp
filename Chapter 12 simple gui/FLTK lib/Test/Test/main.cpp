#include "IO_Window.h"
#include <iostream>

using namespace TestGUI;


int main() 
{
	IO_Window *window1[1];
	for (int i = 0; i < 1; i++) {
		window1[i] = new IO_Window(350, 180, "Test");
	}
	return Fl::run();
}
