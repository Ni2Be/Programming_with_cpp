#pragma once
#include "error.h"
#include <iostream>

namespace Calendar {



	class Date {
	public:
		enum Month {
			jan = 1, feb, mar, apr, mey, jun, jul, aug, sep, oct, nov, dec
		};

		Date(int, Month, int);
		Date();

		int getDay() const { return day; }
		Month getMonth() const { return month; }
		int getYear() const { return year; }

		void addDay(int);
		void addMonth(int);
		void addYear(int);

	private:
		int day;
		Month month;
		int year;
	};

	int daysInMonth(int year, Date::Month mm);

	bool isDate(int dd, Date::Month, int yyyy); // true if valid year

	bool isLeapyear(int yyyy); // true if leapyear

	// comparison operators
	bool operator==(const Date&, const Date&);
	bool operator!=(const Date&, const Date&);

	// in-/output operators
	ostream & operator<<(ostream & os, const Date date);
	istream & operator>>(istream &, Date & date);
}