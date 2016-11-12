#include <iostream>
#include <vector>

#include "Animal.h"

using namespace std;
using namespace Fauna;

int main()
{

	//Mammal mammal1();
	Cat catFelix("Felix", 12);
	Dog dogSpike("Spike", 8);
	Mouse mouseSpeedyGonzales("Speedy Gonzales", 23);

	cout << "Cat, Dog, Mouse:\n"
		<< catFelix.get_sound().c_str() << endl
		<< dogSpike.get_sound().c_str() << endl
		<< mouseSpeedyGonzales.get_sound().c_str() << endl;

	cout << "\n\nold adresses: " << &catFelix << ", " << &dogSpike << ", " << &mouseSpeedyGonzales << endl;
	vector<Animal> animals;

	animals.push_back(catFelix);
	animals.push_back(dogSpike);

	cout << "\n\nnew? adresses: " << &catFelix << ", " << &dogSpike << ", " << &mouseSpeedyGonzales << endl;
	animals.push_back(mouseSpeedyGonzales);
	cout << "\nVector adresses: " << &animals[0] << ", " << &animals[1] << ", " << &animals[2] << endl << endl;

	cout << "Animals:\nCat, Dog, Mouse:\n";
	for (int i = 0; i < animals.size(); i++)
	{
		cout << animals[i].get_name().c_str() << endl
			<< animals[i].get_sound().c_str() << endl;
	}

	catFelix.name = "fu";
	dogSpike.name = "fu";
	mouseSpeedyGonzales.name = "fu";

	cout << "\n\nNames changed\nAnimals:\nCat, Dog, Mouse:\n";
	for (int i = 0; i < animals.size(); i++)
	{
		cout << animals[i].get_name().c_str() << endl
			<< animals[i].get_sound().c_str() << endl;
	}

	cout << "Cat, Dog, Mouse:\n"
		<< catFelix.get_sound().c_str() << endl
		<< dogSpike.get_sound().c_str() << endl
		<< mouseSpeedyGonzales.get_sound().c_str() << endl
		<< catFelix.get_name().c_str() << endl
		<< dogSpike.get_name().c_str() << endl
		<< mouseSpeedyGonzales.get_name().c_str() << endl;

	Animal cat1("kitty", "", 2, "green");
	Animal cat2(cat1);
	Animal cat3 = cat1;

	cout << "\nCats:\n" 
		<< cat1.color << endl
		<< cat2.color << endl
		<< cat3.color << endl;

	cat1.color = "blue";

	cout << "\n\nName change:\nCats:\n"
		<< cat1.color << endl
		<< cat2.color << endl
		<< cat3.color << endl;

	cout << "\nCats:\n"
		<< cat1.color << endl
		<< cat2.color << endl
		<< cat3.color << endl;

	cat2.color = "frank";

	cout << "\n\nName change:\nCats:\n"
		<< cat1.color << endl
		<< cat2.color << endl
		<< cat3.color << endl;

	//Cat *catpoiter = new Cat("pointie", 7);

	//delete(catpoiter);

	//class Mammal : Animal
	//public: legs 
	//private: numberOfTeeth
	//private: isPregnant
	
	//Cat : private Mammal
	//Dog : public Mammal
	//Mouse : Mammal
	//---------------------------------

	//mammal1.legs = 4;
	//catFelix.legs = 4;
	//dogSpike.legs = 4;
	//mouseSpeedyGonzales.legs = 4;

	//mammal1.isPregnant = true;
	//catFelix.isPregnant = true;
	//dogSpike.isPregnant = true;
	//mouseSpeedyGonzales.isPregnant = true;

	//mammal1.numberOfTeeth = 0;
	//catFelix.numberOfTeeth = 30
	//dogSpike.numberOfTeeth = 42;
	//mouseSpeedyGonzales.numberOfTeeth = 16;

	//vector<Cat> cats;
	//cats.push_back((Cat)mammal1);
	//cats.push_back(catFelix);
	//cats.push_back((Cat)dogSpike);
	//cats.push_back((Cat)mouseSpeedyGonzales);

	//vector<Mammal> mammals;

	//mammals.push_back(mammal1);
	//mammals.push_back((Mammal)catFelix);
	//mammals.push_back((Mammal)dogSpike);
	//mammals.push_back((Mammal)mouseSpeedyGonzales);

}