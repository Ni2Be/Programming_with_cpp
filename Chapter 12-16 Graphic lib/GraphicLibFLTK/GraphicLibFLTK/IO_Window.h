#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>


#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

#include "Shape.h"


namespace TestGUI 
{

	//WindowID not used at the Moment
	static int globalWindowID = 0;

	class IO_Window : public Fl_Window
	{
	public:
		IO_Window();
		IO_Window(int w, int h, const char *title);
		~IO_Window() {}

		//TODO Widget vactor implementation
		void attatch(Fl_Widget *w);
		void attatchButton(Fl_Widget *w);

		Fl_Button *translateButton;
		Fl_Button *translateButton2;
		Fl_Button *exitButton;
		Fl_Input *inbox;
		Fl_Output *output;
		Draw::Line *l1;
	private:
		std::vector<Fl_Widget*> widgets;
		std::vector<Fl_Widget*> shapes;

		//WindowID not used at the Moment
		int WindowID;
		void draw();
		static void cb_quit(Fl_Widget* w, void* v);
		static void cb_translateText(Fl_Widget* w, void* window);
		static void cb_translateText_hex(Fl_Widget* w, void* window);
		void translateText(bool toHex);
	};
}
