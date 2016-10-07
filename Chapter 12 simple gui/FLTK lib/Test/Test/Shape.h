#pragma once
#include <FL/fl_draw.h>

namespace Draw {
	class Line : public Fl_Widget
	{
	public:
		Line(int x1, int y1, int x2, int y2) : Fl_Widget(x1, y1, x2, y2) {}
		void draw();
	};
}
