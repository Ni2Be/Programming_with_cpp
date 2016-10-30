#include "Animal.h"


using namespace std;

namespace Animal
{
	string Animal::make_sound()
	{
		return "hallo";
	}
	string Animal::get_sound()
	{
		return "hallo";
	}

	Animal::Animal()
	{

	}

	Cat::Cat()
	{
	}
	string Cat::get_sound()
	{
		return "hallo";
	}
}