#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <random>
#include "Item.h"


void vector_test();
void list_test();
void map_test();
void more_tests();

void generate_nums(int amount, std::string out);
void more_vec();

int main()
{
	//vector_test();
	//list_test();
	//map_test();
	//more_tests();

	more_vec();

	char ch;
	std::cin >> ch;
}

void vector_test()
{
	std::vector<Test_Area::Item> iv = Test_Area::read_ff<std::vector<Test_Area::Item>>("items.txt");

	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);

	std::cout << "\nSort name:\n";
	std::sort(iv.begin(), iv.end(),
		[](const Test_Area::Item& a, const Test_Area::Item& b) -> bool
	{
		return a.name < b.name;
	});
	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);

	std::cout << "\nSort value:\n";
	std::sort(iv.begin(), iv.end(),
		[](const Test_Area::Item& a, const Test_Area::Item& b) -> bool
	{
		return a.value < b.value;
	});
	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);

	std::cout << "\nInsert:\n";
	iv.push_back(Test_Area::Item("Horseshoe", 99, 12.34));
	iv.push_back(Test_Area::Item("Canon S400", 9988, 499.95));
	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);

	std::cout << "\nDelete with name:\n";
	std::vector<Test_Area::Item>::iterator del = std::find_if(iv.begin(), iv.end(),
		[](Test_Area::Item& i) -> bool { return i.name == "Canon S400"; });
	iv.erase(del);
	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);

	std::cout << "\nDelete with ID:\n";
	del = std::find_if(iv.begin(), iv.end(),
		[](Test_Area::Item& i) -> bool { return i.iid == 1; });
	iv.erase(del);
	Test_Area::print_items<std::vector<Test_Area::Item>>(iv);
}

void list_test()
{
	std::list<Test_Area::Item> il = Test_Area::read_ff<std::list<Test_Area::Item>>("items.txt");

	Test_Area::print_items<std::list<Test_Area::Item>>(il);

	std::cout << "\nSort name:\n";
	il.sort([](const Test_Area::Item& a, const Test_Area::Item& b) -> bool
	{
		return a.name < b.name;
	});
	Test_Area::print_items<std::list<Test_Area::Item>>(il);

	std::cout << "\nSort value:\n";
	il.sort([](const Test_Area::Item& a, const Test_Area::Item& b) -> bool
	{
		return a.value < b.value;
	});
	Test_Area::print_items<std::list<Test_Area::Item>>(il);

	std::cout << "\nInsert:\n";
	il.push_back(Test_Area::Item("Horseshoe", 99, 12.34));
	il.push_back(Test_Area::Item("Canon S400", 9988, 499.95));
	Test_Area::print_items<std::list<Test_Area::Item>>(il);

	std::cout << "\nDelete with name:\n";
	std::list<Test_Area::Item>::iterator del = std::find_if(il.begin(), il.end(),
		[](Test_Area::Item& i) -> bool { return i.name == "Canon S400"; });
	il.erase(del);
	Test_Area::print_items<std::list<Test_Area::Item>>(il);

	std::cout << "\nDelete with ID:\n";
	del = std::find_if(il.begin(), il.end(),
		[](Test_Area::Item& i) -> bool { return i.iid == 1; });
	il.erase(del);
	Test_Area::print_items<std::list<Test_Area::Item>>(il);
}

void map_test()
{
	std::vector<Test_Area::Item> iv = Test_Area::read_ff<std::vector<Test_Area::Item>>("items.txt");

	std::map<std::string, double> vals;
	for (auto i : iv)
		vals[i.name] = i.value;

	std::map<std::string, int> ids;
	for (auto i : iv)
	{
		ids[i.name] = i.iid;
	}
	for (std::map<std::string, double>::iterator i = vals.begin(); i != vals.end(); i++)
		std::cout << i->first << ": " << i->second << ", " << ids[i->first] << std::endl;
}

void more_tests()
{
	std::vector<Test_Area::Item> iv = Test_Area::read_ff<std::vector<Test_Area::Item>>("items.txt");

	std::map<std::string, double> vals;
	for (auto i : iv)
		vals[i.name] = i.value;

	std::map<std::string, int> ids;
	for (auto i : iv)
	{
		ids[i.name] = i.iid;
	}

	std::vector<std::pair<std::string, double>> pairV(vals.size());
	std::copy(vals.begin(), vals.end(), pairV.begin());
}

void generate_nums(int amount, std::string out)
{
	std::ofstream of(out.c_str());
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-20, 20);
	for (int n = 0; n < amount; n++) {
		of << dis(gen) << std::endl;
	}
}

void more_vec()
{
	std::string file = "doubles.txt";

	//generate_nums(16, file);

	//read file back
	std::ifstream in(file.c_str());
	std::istream_iterator<double> ii(in);
	std::istream_iterator<double> eos;
	std::vector<double> doub(ii, eos);

	//print
	for (std::vector<double>::iterator i = doub.begin(); i < doub.end(); i++)
		std::cout << *i << std::endl;

	//copy without rounding
	std::vector<int> cop(doub.begin(), doub.end());

	//print
	for (int i = 0; i < doub.size(); i++)
		std::cout << doub[i] << " - " << cop[i] << " = " << doub[i] - cop[i] << std::endl;

	//
	std::reverse(doub.begin(), doub.end());

	//print
	for (std::vector<double>::iterator i = doub.begin(); i < doub.end(); i++)
		std::cout << *i << std::endl;

	//
	double ave = std::accumulate(doub.begin(), doub.end(), 0.0) / doub.size();
	std::cout << "average: " << ave << std::endl;

	//copy over average
	int counter = 0;
	std::vector<double> doub2(doub.size());
	std::copy_if(doub.begin(), doub.end(), doub2.begin(),
		[ave, &counter](double& d)->bool
	{
		if (d > ave)
		{
			counter++;
			return true;
		}
		return false;
	});
	doub2.erase(doub2.begin() + counter, doub2.end());

	//print
	for (std::vector<double>::iterator i = doub2.begin(); i < doub2.end(); i++)
		std::cout << *i << std::endl;

	//
	std::sort(doub.begin(), doub.end());

	//print
	for (std::vector<double>::iterator i = doub.begin(); i < doub.end(); i++)
		std::cout << *i << std::endl;

}
