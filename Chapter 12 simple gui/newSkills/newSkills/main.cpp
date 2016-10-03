//#include "GUI.h"
//#include "Layout.h"

//void callback1(Fl_Widget*, void*){}
//#include "Point.h"
#include "Window.h"
//#include "Graph.h"
//#include "fltk.h"
#include <string>

//using namespace Graph_lib;

int main() {
	//Point p(100, 100);

	Graph_lib::Window window1(400, 400, "Hallo");
	
//	Line l1(Point(100, 100), Point(200, 200));

//	window1.attach(l1);
	/*
	Windows window(Point(100, 100), 400, 400, "Best GUI!");
	Line xaxis(Point(50, 350), Point(350, 350), 1, FL_BLACK);
	Line yaxis(Point(50, 350), Point(50, 50), 1, FL_BLACK);
	Text xtext(Point(350, 355), FL_HELVETICA, 22, FL_BLACK, "x");
	Text ytext(Point(45, 45), FL_HELVETICA, 22, FL_BLACK, "y");
	Slider slider1(Point(50, 50), 100, 40, "slider");
	In_box inBox1(Point(150, 150), 100, 40, "inBox");
	Out_box outBox1(Point(200, 200), 100, 50, "Text der\nhier steht!");
	Button button1(Point(100, 100), 100, 30, "go!", callback1);

	window.attach(xaxis);
	window.attach(yaxis);
	window.attach(xtext);
	window.attach(ytext);
	window.attach(inBox1);
	window.attach(outBox1);
	
	window.attach(slider1);
	window.attach(button1);
*/
}