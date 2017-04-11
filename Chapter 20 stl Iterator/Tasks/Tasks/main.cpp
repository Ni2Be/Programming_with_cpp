#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <numeric>

template <class Iterator>
void fill(Iterator front, Iterator end);

template <class Autoprintable>
void auto_print(Autoprintable autoprint);

template <class Autoincrement, class T>
void auto_increment(Autoincrement& autoincrement, T val);

template <class Iterator1, class Iterator2>
Iterator2 N2B_copy(Iterator1 front1, Iterator1 end1, Iterator2 front2);


int main()
{
	std::cout << "Fill:\n";
	std::array<int, 10> arr1;
	std::vector<int> vec1(10);
	std::list<int> list1(10);

	fill(arr1.begin(), arr1.end());
	fill(vec1.begin(), vec1.end());
	fill(list1.begin(), list1.end());
	//std::iota(arr1.begin(), arr1.end(), 0);
	//std::iota(vec1.begin(), vec1.end(), 0);
	//std::iota(list1.begin(), list1.end(), 0);

	auto_print(arr1);
	std::cout << std::endl;
	auto_print(vec1);
	std::cout << std::endl;
	auto_print(list1);
	std::cout << std::endl;
	
	std::cout << "Copy:\n";
	std::array<int, 10> arr2(arr1);
	std::vector<int> vec2(vec1);
	std::list<int> list2(list1);

	auto_print(arr2);
	std::cout << std::endl;
	auto_print(vec2);
	std::cout << std::endl;
	auto_print(list2);
	std::cout << std::endl;

	std::cout << "Increment:\n";
	auto_increment(arr2, 2);
	auto_increment(vec2, 3);
	auto_increment(list2, 6);

	auto_print(arr2);
	std::cout << std::endl;
	auto_print(vec2);
	std::cout << std::endl;
	auto_print(list2);
	std::cout << std::endl;

	std::cout << "\"Better\" Copy:\n";
	std::array<int, 10> arr3;
	std::vector<int> vec3(10);
	std::list<int> list3(10);

	N2B_copy(arr1.begin(), arr1.end(), vec3.begin());
	N2B_copy(list1.begin(), list1.end(), arr3.begin());
	N2B_copy(vec1.begin(), vec1.end(), list3.begin());

	auto_print(arr3);
	std::cout << std::endl;
	auto_print(vec3);
	std::cout << std::endl;
	auto_print(list3);
	std::cout << std::endl;

	std::cout << "Find:\n";
	std::cout << "3 in arr?:\n";
	auto res1 = std::find(arr1.begin(), arr1.end(), 3);
	if (res1 != std::end(arr1))
		std::cout << "yes!\n";
	else
		std::cout << "no!\n";
	std::cout << "27 in list?:\n";
	auto res2 = std::find(list2.begin(), list2.end(), 27);
	if (res2 != std::end(list2))
		std::cout << "yes!\n";
	else
		std::cout << "no!\n";
	
	char ch;
	std::cin >> ch;
}

template <class Iterator>
void fill(Iterator front, Iterator end)
{
	int i = 0;
	while (front != end)
	{
		*front = i;
		i++;
		front++;
	}
}

template <class Autoprintable>
void auto_print(Autoprintable autoprint)
{
	//call by value
	for (auto item : autoprint)
	{
		std::cout << item << ' ';
	}
}

template <class Autoincrement, class T>
void auto_increment(Autoincrement& autoincrement, T val)
{
	//call by reference
	for (auto&& item : autoincrement)
	{
		item += val;
	}
}

template <class Iterator1, class Iterator2>
Iterator2 N2B_copy(Iterator1 front1, Iterator1 end1, Iterator2 front2)
{
	Iterator2 temp = front2;
	while (front1 != end1)
	{
		*front2 = *front1;
		front1++;
		front2++;
	}
	return temp;
}

