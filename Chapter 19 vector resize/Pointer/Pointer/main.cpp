#include <iostream>
#include <chrono>

#define RAMTEST
#include "Pointer.h"

#ifdef RAMTEST
void ram_emtying_test();
void ram_fill_function();
void ram_local_function();
void ram_neutral_function();
#endif

void counter_test();

int main()
{

#ifdef RAMTEST
	ram_emtying_test();
#else
	counter_test();
#endif

	std::cout << "end" << std::endl;
	char ch;
	std::cin >> ch;
}

void ram_emtying_test()
{
	std::cout << "ram test:" << std::endl;
	std::cout << "ram should fill up, go?" << std::endl;
	char ch;
	std::cin >> ch;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	ram_fill_function();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "filling took: "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
		<< " micro sec\n\n";

	std::cout << "ram should not fill up local, go?" << std::endl;
	std::cin >> ch;
	start = std::chrono::steady_clock::now();
	ram_local_function();
	end = std::chrono::steady_clock::now();
	std::cout << "not filling took: "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
		<< " micro sec\n\n";

	std::cout << "ram should not fill up counted pointer, go?" << std::endl;
	std::cin >> ch;
	start = std::chrono::steady_clock::now();
	ram_neutral_function();
	end = std::chrono::steady_clock::now();
	std::cout << "not filling took: "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
		<< " micro sec\n\n";
}

void ram_fill_function()
{	for (int i = 0; i < 100000; i++)
	{
		double* temp = new double(23);
	}
}

void ram_local_function()
{
	for (int i = 0; i < 100000; i++)
	{
		double* temp = new double(23);
		delete temp;
	}
}

void ram_neutral_function()
{
	for (int i = 0; i < 100000; i++)
	{
		not_std::counted_pointer<double> cp(new double(23));
	}
}

void counter_test()
{
	std::cout << "counter test:" << std::endl;
	int* n = new int(9);
	not_std::counted_pointer<int> cp1(n);
	not_std::counted_pointer<int> cp2(cp1);

	std::cout << *cp1 << " " << *cp2 << std::endl;

	std::cout << "counter1:" << cp1.get_counter() << std::endl;
	std::cout << "counter2:" << cp2.get_counter() << std::endl;
	*cp2 = 2;
	for (int i = 0; i < 1; i++)
	{
		not_std::counted_pointer<int> cp3(cp1);

		std::cout << "counter1:" << cp1.get_counter() << std::endl;
		std::cout << "counter3:" << cp3.get_counter() << std::endl;

		std::cout << *cp2 << " " << *cp3 << std::endl;
	}

	std::cout << "counter1:" << cp1.get_counter() << std::endl;
	std::cout << "counter2:" << cp2.get_counter() << std::endl;
	std::cout << *cp1 << " " << *cp2 << std::endl;

	std::cout << *cp1 << " " << *cp2 << std::endl;
}