#include "Shape.h"

namespace Draw {
	void Line::draw() {
		fl_color(FL_BLACK);
		int x1 = x(), y1 = y();
		int x2 = x() + 100, y2 = y() + 100;
		fl_line(x1, x2, x(), y());
	}
}
