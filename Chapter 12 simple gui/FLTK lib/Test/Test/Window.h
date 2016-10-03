#include <vector>

#include "fltk.h"
#include "Point.h"


namespace Graph_lib {

	class Shape;	// "forward declare" Shape

	class Window : public Fl_Window {
	public:
		Window(int w, int h, const std::string& title);			// let the system pick the location
		Window(Point xy, int w, int h, const std::string& title);	// top left corner in xy
		virtual ~Window() { }

		int x_max() const { return w; }
		int y_max() const { return h; }
		
		void attach(Shape& s);
		/*
		void resize(int ww, int hh) { w = ww, h = hh; size(ww, hh); }

		void set_label(const std::string& s) { label(s.c_str()); }

		void detach(Shape& s);	// remove s from shapes 

		void put_on_top(Shape& p);	// put p on top of other shapes
		*/
	protected:
		void draw();

	private:
		std::vector<Graph_lib::Shape*> shapes;	// shapes attached to window
		int w, h;					// window size

		void init();
	};
}