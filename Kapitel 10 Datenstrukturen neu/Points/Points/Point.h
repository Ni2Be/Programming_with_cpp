#pragma once
#include <string>
#include <iostream>
#include "error.h"

struct Point
{
public:
	//Members
	int x;
	int y;

	//Constructors
	Point();
	Point(int inx, int iny);
	~Point();

};

//Operators
std::ostream& operator<<(std::ostream& ostr, const Point& p);
std::istream& operator>>(std::istream& istr, Point& p);

bool operator==(Point & a, Point & b);
bool operator!=(Point & a, Point & b);
