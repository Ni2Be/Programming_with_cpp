#include "IO_Window.h"
#include <iostream>

using namespace TestGUI;


int main() 
{
	const int h = 180, w = 350;
	IO_Window *window1;

	window1 = (IO_Window*) malloc(sizeof(IO_Window));//no sense, just a try

	//DEBUG
	for (int i = 0; i < 2; i++) {
		window1 = new IO_Window(w, h, "Test");
	}
	//for (int i = 0; i < 100; i++)
	//{
	//	window1->attatch(new Draw::Line(0, i * 1, 150 - 1, 50));
	//}
	//ENDDEBUG
	return Fl::run();
}
