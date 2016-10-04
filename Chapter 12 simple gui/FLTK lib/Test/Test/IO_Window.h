#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>


#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

namespace TestGUI 
{
	static int globalWindowID = 0;

	class IO_Window : public Fl_Window
	{
	public:
		IO_Window(int w, int h, const char *title);
		~IO_Window() {}

		Fl_Button *copyButton;
		Fl_Button *exitButton;
		Fl_Input *inbox;
		Fl_Output *output;
	private:
		int WindowID;

		static void cb_quit(Fl_Widget* w, void* v);
		static void cb_copyText(Fl_Widget* w, void* window);
		void copyText();
	};
}
