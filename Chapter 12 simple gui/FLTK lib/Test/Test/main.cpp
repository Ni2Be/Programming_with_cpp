#include "IO_Window.h"
#include <iostream>

using namespace TestGUI;


int main() 
{
	const int h = 180, w = 350;
	IO_Window *window1;
	for (int i = 0; i < 1; i++) {
		window1 = new IO_Window(w, h, "Test");
	}
	//window1->attatch(new Draw::Line(0, 50, 150, 50));
	
	return Fl::run();
}
