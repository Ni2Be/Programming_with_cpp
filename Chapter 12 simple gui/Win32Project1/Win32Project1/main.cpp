#include <FL/Fl.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.h>
#include "D:/Programmieren/Programming_with_cpp/GraphicLib/Stoustrupinclude/Point.h"
#include <vector>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H> 
#include <FL/Fl_Input.H> 
#include <FL/Fl_Output.H> 
#include <cstdlib>       // for exit(0)
#include <FL/fl_draw.H>
#include <FL/Enumerations.H>

#include <Fl/Fl_JPEG_Image.H>
#include <Fl/Fl_GIF_Image.H>



using namespace Graph_lib;

int main() {
	Point tl(100, 100);
	Fl_Window window(600, 600, "Window title");
	Fl_Box box(0, 0, 200, 200, "Hello World");

	std::vector<Point> points;
	points.push_back(Point(110, 110));
	points.push_back(Point(150, 150));
	points.push_back(Point(210, 100));

	for (unsigned int i = 1; i<points.size(); ++i)
		fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);

	window.show();
	return Fl::run();
}