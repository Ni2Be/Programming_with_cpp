#include "IO_Window.h"
#include "Shape.h"

using namespace TestGUI;

int main() 
{
	IO_Window *window1[1];
	for (int i = 0; i < 1; i++) {
		window1[i] = new IO_Window(350, 180, "Test");
		Draw::Line(10, 10, 100, 100);
	}
	return Fl::run();
}
