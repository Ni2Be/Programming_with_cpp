#include <iostream>


using namespace std;

namespace Fauna
{
	class Animal
	{
	public:
		string name;
		const char *color;
		virtual ~Animal() { std::cout << "\n~Animal"; };
		string make_sound();
		string get_sound();
		string get_name();
		Animal(string name, string sound, int age, char* color)
			:name(name), sound(sound), age(age), color(color) {}
	protected:
		Animal(string name, string sound, int age)
			:name(name), sound(sound), age(age) {}
		
		string sound;
	private:
		int age;
	};

	class Mammal : public Animal
	{
	public:
		int legs;
	protected:
		Mammal(string name, string sound, int age)
			: Animal(name, sound, age) {}
		int numberOfTeeth;
		virtual ~Mammal() { std::cout << "\n~Mammal"; };
	private:
		bool isPregnant;
	};

	class Cat : public Mammal
	{
	public:
		Cat(string name, int age)
			: Mammal(name, "Meow", age) {}
		~Cat() { std::cout << "\n~Cat"; };
	};

	class Dog : public Mammal
	{
	public:
		Dog(string name, int age)
			: Mammal(name, "Woof", age) {}
		~Dog() { std::cout << "\n~Dog"; };
	};

	class Mouse: public Mammal
	{
	public:
		Mouse(string name, int age)
			: Mammal(name, "Peep", age) {}
		string get_sound();
		~Mouse() { std::cout << "\n~Mouse"; };
	};
}