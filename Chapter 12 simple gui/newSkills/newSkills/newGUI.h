#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>

#include <vector>
#include <string>
#include <fstream>

struct Windows;
using namespace std;
using Callback = void(*)(Fl_Widget*, void*);

int w{ Fl::w() / 2 }, h{ Fl::h() };


#include "Shape.h"
#include "Widget.h"

struct Windows : Fl_Double_Window {
	Windows(Point topleft, int width, int height, string title)
		: Fl_Double_Window(topleft.x, topleft.y, width, height, title.c_str()) {
		color(FL_WHITE);
		show();
	}

	vector<Shape*> shapes;
	void attach(Shape& s) { shapes.push_back(&s); }
	
	void attach(Widget& w) {
		begin();
		w.attach(*this);
		end();
	}

	void draw() {
		Fl_Double_Window::draw();
		for (int i = 0; i < shapes.size(); i++) {
			shapes[i]->draw();
		}
	}
};
