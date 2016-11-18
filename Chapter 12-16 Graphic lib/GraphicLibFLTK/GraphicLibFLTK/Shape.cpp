#include "Shape.h"

namespace Draw {
	void Line::draw() {
		fl_color(FL_BLACK);
		int x1 = x(), y1 = y();
		fl_line(x1, y1, x1 + 100, y1);
	}
}
