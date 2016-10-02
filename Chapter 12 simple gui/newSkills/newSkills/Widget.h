#pragma once

struct Widget {
	int width, height;
	string label;
	Point xy;
	Callback do_it;
	Windows *own;

	Widget(Point p, int width, int height, string label, Callback cb)
		: xy(p), width(width), height(height), label(label), do_it(cb) {}
	virtual void attach(Windows&) {}
};

struct Slider : Widget {
	Fl_Slider* pw;
	Slider(Point p, int w, int h, string label)
		:Widget(p, w, h, label, 0) {}
	void set_value(int val) { pw->value(val); }
	int get_value() { return pw->value(); }
	
	void set_bounds(int b1, int b2) { pw->bounds(b1, b2); }
	void attach(Windows &window) {
		pw = new Fl_Slider(xy.x, xy.y, width, height, label.c_str());
		pw->type(FL_HOR_NICE_SLIDER);
		pw->align(FL_ALIGN_RIGHT);
		pw->labelfont(FL_COURIER);
		pw->labelcolor(FL_BLACK);
		pw->labelsize(14);
		own = &window;
	}
};

struct In_box : Widget {
	Fl_Input* pw;
	In_box(Point p, int w, int h, string label)
		:Widget(p, w, h, label, 0) {}
	void set_value(string s) { pw->value(s.c_str()); }
	string get_value() { return (string)pw->value(); }

	void attach(Windows &window) {
		pw = new Fl_Input(xy.x, xy.y, width, height, label.c_str());
		pw->align(FL_ALIGN_RIGHT);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_BLACK);
		pw->textsize(12);
		pw->labelfont(FL_COURIER);
		pw->labelcolor(FL_BLACK);
		pw->labelsize(14);
		own = &window;
	}
};

struct Button : Widget {
	Fl_Button* pw;
	Button(Point p, int w, int h, string label, Callback cb)
		:Widget(p, w, h, label, cb) {}

	void attach(Windows &window) {
		pw = new Fl_Button(xy.x, xy.y, width, height, label.c_str());
		pw->callback(do_it);
		pw->color(FL_DARK_MAGENTA);
		pw->align(FL_ALIGN_RIGHT);
		pw->labelfont(FL_COURIER);
		pw->labelcolor(FL_BLACK);
		pw->labelsize(14);
		own = &window;
	}
};

struct Out_box : Widget {
	Fl_Text_Display* pw;
	Fl_Text_Buffer* buff;
	Out_box(Point p, int w, int h, string label)
		:Widget(p, w, h, label, 0) {}
	void set_value(string s) { buff->text(s.c_str()); }

	void attach(Windows &window) {
		pw = new Fl_Text_Display(xy.x, xy.y, width, height, label.c_str());
		buff = new Fl_Text_Buffer();
		pw->buffer(buff);

		pw->align(FL_ALIGN_RIGHT);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_BLACK);
		pw->textsize(12);
		pw->labelfont(FL_COURIER);
		pw->labelcolor(FL_BLACK);
		pw->labelsize(14);
		own = &window;
	}
};
