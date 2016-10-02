#pragma once
#include <vector>
#include <FL/fl_draw.H>
#include <string>

struct Point {

	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

struct Shape {
public:
	int line_width, line_color, fill_color;
	std::vector<Point> pts;

	Shape(int lw, int lc, int fc)
		: line_width(lw), line_color(lc), fill_color(fc) {}

	void add(Point p) {
		pts.push_back(p);
	}
	void move(int dx, int dy) {
		for (int i = 0; i < pts.size(); i++) {
			pts[i].x += dx;
			pts[i].y += dy;
		}
	}
	virtual void draw() {};
};

struct Line : Shape {
	Line(Point p1, Point p2, int lw, int lc)
		: Shape(lw, lc, 0) {
		add(p1);
		add(p2);
	}
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(line_color);
		fl_line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
	}
};

struct Circle : Shape {
	int radius;
	Circle(Point p, int r, int lw, int lc, int fc)
		: radius(r), Shape(lw, lc, fc) {
		add(p);
		move(-radius, -radius);
	}
	
	void relocate(int xnew, int ynew) {
		pts[0].x = xnew - radius;
		pts[0].y = ynew - radius;
	}
	
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(fill_color);
		fl_pie(pts[0].x, pts[0].y, 2 * radius - 1, 2 * radius - 1, 0, 360);
		fl_color(line_color);
		fl_arc(pts[0].x, pts[0].y, 2 * radius, 2 * radius, 0, 360);
	}
};

struct Text : Shape {
	int font;
	std::string content;
	Text(Point p, int font, int lw, int lc, std::string s)
		: font(font), content(s), Shape(lw, lc, 0) {
		add(p);
	}

	void draw() {
		fl_font(font, line_width);
		fl_color(line_color);
		fl_draw(content.c_str(), pts[0].x, pts[0].y);
	}
};
