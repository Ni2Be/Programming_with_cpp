#pragma once
#include <iostream>
#include <stdio.h>

#include "Error.h"
#include "Day.h"
#include "Month.h"
#include "Year.h"

struct Reading
{
public:
	int day;
	int hour;
	double measuring;
};

std::istream& operator>>(std::istream& istr, Reading& reading);

std::istream& operator>>(std::istream& istr, Dates::Month& month);

std::istream& operator>>(std::istream& istr, Dates::Year& year);