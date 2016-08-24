#pragma once
#include <vector>
#include "Day.h"

namespace Dates {
	enum Months {
		not_a_month, jan, feb, mar, apr, mey, jun, jul, aug, sep, oct, nov, dec
	};

	struct Month
	{
		int month;
		std::vector <Day> days;

		// days in a month will start at days[1]
		Month() :month(not_a_month), days(32) {}
	};
}