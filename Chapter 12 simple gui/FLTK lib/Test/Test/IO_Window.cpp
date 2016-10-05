#include "IO_Window.h"

namespace TestGUI {

	IO_Window::IO_Window(int w, int h, const char *title = 0) : Fl_Window(w, h, title)
	{
		WindowID = globalWindowID++;
		resizable(this);

		begin();
		copyButton = new Fl_Button(10, h - 45, 100, 35, "Cop&y");
		exitButton = new Fl_Button(120, h - 45, 100, 35, "E&xit");
		inbox = new Fl_Input(w / 4, 10, 2 * w / 4, 35, "In:");
		output = new Fl_Output(w / 4, 55, 2 * w / 4, 35, "Out:");
		end();

		copyButton->callback(cb_copyText, this);
		exitButton->callback(cb_quit, this);

		callback(cb_quit, this);
		show();
	}

	void IO_Window::cb_quit(Fl_Widget* w, void* v)
	{
		((Fl_Window*)v)->hide();
	}

	void IO_Window::cb_copyText(Fl_Widget* w, void* window)
	{
		((IO_Window*)window)->copyText();
	}

	void IO_Window::copyText()
	{
		output->value(inbox->value());
	};
}