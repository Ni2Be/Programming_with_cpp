#include "Item.h"


std::ostream& Test_Area::operator<<(std::ostream& os, const Test_Area::Item& i)
{
	os << i.iid << ": " << i.name << ": " << i.value;
	return os;
}

std::istream& Test_Area::operator>>(std::istream& is, Test_Area::Item& i)
{
	is >> i.iid >> i.name >> i.value;
	return is;
}
