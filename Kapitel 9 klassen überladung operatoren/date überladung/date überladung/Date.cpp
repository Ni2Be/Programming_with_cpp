#include "Date.h"

namespace Calendar{


	//CONSTRUCTORS
	Date::Date(int dd, Month mm, int yyyy) 
	{
		if (isDate(dd, mm, yyyy)) { day = dd, month = mm, year = yyyy; }
		else {
			error("Calendar::Date::Date(int,Month,int)","not a valid Date");
		}
	}

	Date& defoultDate() {
		static Date temp(01, Date::jan, 1970);
		return temp;
	}

	Date::Date() 
	:day(defoultDate().year), month(defoultDate().month), year(defoultDate().year){}
	
	//FUNCTIONS
	void Date::addDay(int days) {
		if (days < 0) error("Calendar::Date::addDay", "No negative values!");

		int monthlength = 0;
		int daysThisMonth = 0;

		while (days != 0) {
			monthlength = daysInMonth(year, month);
			daysThisMonth = monthlength - Date::day;

			if (daysThisMonth - days < 0) {
				Date::addMonth(1);
				Date::day = 0;
				days -= daysThisMonth;
			}
			else {
				Date::day += days;
				break;
			}
		}
	}

	void Date::addMonth(int months) {
		int tempMonth = Date::month;
		int tempYear = Date::year;
		int monint = 0;
		monint = Date::month;

		for (int i = 0; i < months; i++) {
			if (monint + 1 > 12) {
				monint = 1;
				Date::addYear(1);
			}
			else {
				monint += 1;
			}
		}

		// if the beginning month has more days than the new one and the day is over 30
		// the Day will be set to the last day of the new month
		// to ensure that no invalid date like (31.02.2012)
		// will be saved
		if ((Date::day >= 30) && 
			(daysInMonth(tempYear, Month(tempMonth)) 
				> daysInMonth(Date::year, Month(monint))))
		{
			Date::day = daysInMonth(Date::year, Month(monint));
		}
		// same for feb
		if ((Date::month == feb) && (Date::day >= 28) &&
			(daysInMonth(tempYear, Month(tempMonth))
				> daysInMonth(Date::year, Month(monint))))
		{
			Date::day = daysInMonth(Date::year, Month(monint));
		}
		// DRY

		Date::month = Month(monint);
	}

	void Date::addYear(int years) {
		if (Date::day == 29 && Date::month == feb
			&& !isLeapyear(Date::year + years)) 
		{ 
			Date::day = 28;
			Date::month = feb;
		}
		Date::year += years;
	}
	
	// returns ture if valid date
	bool isDate(int dd, Date::Month mm, int yyyy) {
		if (dd <= 0) return false;
		int days = 0;
		days = daysInMonth(yyyy, mm);
		if (dd > days) return false;
		if (mm < 1 || mm > 12) return false;
		return true;
	}

	// returns the amount of the days in the month
	int daysInMonth(int year, Date::Month mm) {
		int daysInMonth = 0;
		switch (mm)
		{
		case Date::feb:
			(isLeapyear(year) ? daysInMonth = 29 : daysInMonth = 28);
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			daysInMonth = 30;
			break;
		default:
			daysInMonth = 31;
			break;
		}
		return daysInMonth;
	}

	// true if leapyear
	bool isLeapyear(int yyyy) {
		if (((yyyy % 4 == 0) && (yyyy % 100 != 0)) || (yyyy % 400 == 0)) return true;
		return false;
	}
	

	// comparison operators
	bool operator==(const Date& a, const Date& b) {
		return (a.getYear() == b.getYear()) &&
			(a.getMonth() == b.getMonth()) &&
			(a.getDay() == b.getDay());
	}

	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	// in-/output operators
	istream & operator>>(istream & is, Date & date) {
		int yyyy, mm, dd;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> dd >> ch2 >> mm >> ch3 >> yyyy >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != '.' || ch3 != '.' || ch4 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
		date = Date(dd, Date::Month(mm), yyyy);
		return is;
	}

	ostream & operator<<(ostream & os, const Date date) {
		return os << '(' << date.getDay() << '.' << date.getMonth() << '.' << date.getYear() << ')';
	}
}
