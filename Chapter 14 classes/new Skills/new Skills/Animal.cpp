#include "Animal.h"


using namespace std;

namespace Fauna
{
	string Animal::get_sound()
	{
		return sound + " Animal";
	}

	string Animal::get_name()
	{
		return "Name: " + name;
	}


	string Mouse::get_sound()
	{
		return sound + " Mouse";
	}
}