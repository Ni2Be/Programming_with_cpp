#include "Reading.h"

int string_to_month(std::string monthname) {
	if (monthname == "jan") return Dates::jan;
	if (monthname == "feb") return Dates::feb;
	if (monthname == "mar") return Dates::mar;
	if (monthname == "apr") return Dates::apr;
	if (monthname == "mey") return Dates::mey;
	if (monthname == "jun") return Dates::jun;
	if (monthname == "jul") return Dates::jul;
	if (monthname == "aug") return Dates::aug;
	if (monthname == "sep") return Dates::sep;
	if (monthname == "oct") return Dates::oct;
	if (monthname == "nov") return Dates::nov;
	if (monthname == "dec") return Dates::dec;
	return Dates::not_a_month;
}

std::istream& operator>>(std::istream& istr, Reading& reading) {

	char ch1;
	if ((istr >> ch1) && (ch1 != '(')) {
		istr.unget();
		istr.clear(std::ios_base::failbit);
		return istr;
	}

	char ch2;
	int dd;
	int hh;
	double measur;

	istr >> dd >> hh >> measur >> ch2;

	if (!istr || (ch2 != ')')) error("Reading operator>>()", "not a valid ending");

	reading.day = dd;
	reading.hour = hh;
	reading.measuring = measur;

	std::cout << dd << " " << hh << " " << measur << "\n";

	return istr;
}

std::istream& operator>>(std::istream& istr, Dates::Month& month) {
	std::string monthmarker;
	if (!(istr >> monthmarker) || (monthmarker != "month")) {
		istr.unget();
		istr.clear(std::ios_base::failbit);
		return istr;
	}

	std::string temp_month;
	istr >> temp_month;
	month.month = string_to_month(temp_month);
	if (month.month == Dates::not_a_month) error("", "not a valid month");

	char ch1;
	Reading tempreading;
	while ((istr >> ch1) || (ch1 != '}')) {
		istr.unget();
		istr >> tempreading;
		
		month.days[tempreading.day].measuring[tempreading.hour] = tempreading.measuring;
	}

	return istr;
}
