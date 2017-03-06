#include <iostream>
#include <ostream>
#include <vector>
#include <math.h>

void print_array10(std::ostream& os, int* a);

int main()
{
	//1
	int* arr1 = new int[10];
	arr1[0] = 10;
	arr1[9] = 1;

	//2
	for (int i = 0; i < 10; i++)
		std::cout << arr1[i] << " ";

	//3
	delete[] arr1;

	//4
	int arr2[10];
	arr2[0] = 3;
	arr2[7] = 9;
	print_array10(std::cout, arr2);

	//5
	std::cout << std::endl;
	int arr3[] = { 100, 101, 102 };
	for (auto &item : arr3)
		std::cout << item << std::endl;
	
	//6 nope

	//7 nope

	//...

	std::cout << std::endl;
	//1
	int* p1 = new int(7);
	//2
	std::cout << "pointer: " << p1 << ", value: " << *p1 << std::endl;
	//3
	int arr4[] = { 1, 2, 4, 8, 16, 32, 64 };
	int *p2 = arr4;
	//4
	std::cout << "array: " << arr4 << ", pointer: " << p2 << std::endl;
	//5
	int *p3 = p2;
	//6
	p2 = p1;
	//7
	p3 = p2;
	//8
	std::cout << "*p1: " << p1 << ", *p2: " << p2 << std::endl;
	std::cout << "p1: " << *p1 << ", p2: " << *p2 << std::endl;
	//9
	delete p1;
	//10
	int arr5[] = { 1, 2, 4, 8, 16, 32, 64 };
	int *p10 = arr5;
	//11
	int arr6[7];
	int *p11 = arr6;
	//12
	for (int i = 0; i < 7; i++)
		p11[i] = p10[i];
	//13
	std::vector<int> vec1;
	for (int i = 0; i < 7; i++)
	{
		vec1.push_back(pow(2, i));
	}
	std::vector<int> vec2(vec1);

	for (auto &item : vec2)
	{
		std::cout << item << ", ";
	}

	char ch;
	std::cin >> ch;
}

//4
void print_array10(std::ostream& os, int* a)
{
	os << std::endl;
	for (int i = 0; i < 10; i++)
		os << a[i] << ", ";
	os << std::endl;
}

