#include "IO_Window.h"
#include <iostream>

namespace TestGUI {
	IO_Window::IO_Window() : Fl_Window(0, 0, "") {};

	IO_Window::IO_Window(int w, int h, const char *title = 0) : Fl_Window(w, h, title)
	{
		WindowID = globalWindowID++;
		resizable(this);
		
		begin();
		translateButton = new Fl_Button(10, h - 45, 100, 35, "He&x!");
		translateButton2 = new Fl_Button(230, h - 45, 100, 35, "St&ring!");
		exitButton = new Fl_Button(120, h - 45, 100, 35, "Exit");
		inbox = new Fl_Input(w / 4, 10, 2 * w / 4, 35, "In:");
		output = new Fl_Output(w / 4, 55, 2 * w / 4, 35, "Out:");
		l1 = new Draw::Line(10, 10, 100, 10);
		end();
		
		translateButton->callback(cb_translateText_hex, this);
		translateButton2->callback(cb_translateText, this);

		exitButton->callback(cb_quit, this);
		
		callback(cb_quit, this);
		show();
	}

	void IO_Window::cb_quit(Fl_Widget* w, void* v)
	{
		((Fl_Window*)v)->hide();
	}

	void IO_Window::cb_translateText(Fl_Widget* w, void* window)
	{
		((IO_Window*)window)->translateText(false);
	}

	void IO_Window::cb_translateText_hex(Fl_Widget* w, void* window)
	{

		((IO_Window*)window)->translateText(true);
	}

	void IO_Window::translateText(bool toHex)
	{
		string out = inbox->value();
		if(toHex)
			output->value(((const char*)Translator::string_to_hex(out).c_str()));
		else
			output->value(((const char*)Translator::hex_to_string(out).c_str()));
	};
}