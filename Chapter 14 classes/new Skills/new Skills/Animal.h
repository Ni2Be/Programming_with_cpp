#include <iostream>


using namespace std;

namespace Animal
{
	class Animal
	{
	public:
		string make_sound();
		virtual string get_sound();
	private:
		string name;
		string sound = "maaa";
		int age;
	protected:
		Animal();
	};

	class Cat : Animal
	{
	public:
		Cat();
		string get_sound();
	};
}