#pragma once
#include <vector>
#include "Month.h"

namespace Dates {
	const int not_a_year = -9999;

	struct Year
	{
		int year;
		std::vector <Month> months;

		Year() :year(not_a_year), months(12) {}
	};
}