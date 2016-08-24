#include "Point.h"


// Constructors
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int inx, int iny)
{
	x = inx;
	y = iny;
}

Point::~Point()
{
}


//Operators
// returns poit as string "(x,y)"
std::ostream& operator<<(std::ostream& ostr, const Point& p) {
	ostr << '(' + std::to_string(p.x) + ',' + std::to_string(p.y) + ')';
	return ostr;
}

// needs Point as "(x,y)"
std::istream& operator>>(std::istream& istr, Point& p) {
	istr.exceptions(istr.exceptions() | std::ios_base::badbit);

	char ch1, ch2, ch3;
	int x, y;
	istr >> ch1 >> x >> ch2 >> y >> ch3;
	
	if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
		istr.clear();
		error("Point::operator>>", "not a valid Point!");
	}
	p.x = x;
	p.y = y;
	return istr;
}

// returns true if x1 == x2 and y1 == y2
bool operator==(Point & a, Point & b) {
	return ((a.x == b.x) && (a.y == b.y));
}

bool operator!=(Point & a, Point & b) {
	return !(a == b);
}