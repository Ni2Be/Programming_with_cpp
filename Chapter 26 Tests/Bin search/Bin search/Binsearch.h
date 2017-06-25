#pragma once
#include <vector>

#ifdef _WIN32
#define VIS
#endif _WIN32
#ifdef VIS
#include <iostream>
#include <string>
#include <windows.h>
#endif // VIS


/*
first: is called first but it wont allways point at the first position
end: is called end becouse it will allways point to the real end.
*/
template <class Type_Iterator>
Type_Iterator binary_search_v3(Type_Iterator first, Type_Iterator end, typename Type_Iterator::value_type key)
{
	//mid: will point to the value in the middle if the containder has an odd number of
	//values, else to the middle - 1
	Type_Iterator mid;

	//remaining: is the number of values still in the container
	//step: is the number of values of the container mid will advance from first
	typename Type_Iterator::difference_type remaining, step;
	remaining = std::distance(first, end);

	//will move first to the value that is searched, or else if not in the container
	//to the next bigger value or else to end if the end is reached
	while (remaining > 0)
	{
		step = remaining / 2;
		mid = first;
		std::advance(mid, step);
		//if the key is bigger look at the bigger half
		//update remaining
		if (key > *mid)
		{
			std::advance(mid, 1);
			first = mid;
			remaining = remaining - (step + 1);
		}
		//if the key is smaler just update remaining
		else
		{
			remaining = step;
		}
	}

	//proofe if first is now pointing to the right value
	if (first != end && *first == key)
	{
		return first;
	}
	return end;
}




template <class T>
typename T::iterator binary_search_v2(typename T::iterator first, typename  T::iterator end, typename  T::value_type key)
{
	typename T::difference_type remaining, step;
	remaining = std::distance(first, end);

	typename T::iterator mid;

	while (remaining > 0)
	{
		step = remaining / 2;
		mid = first + step;
		if (key > *mid)
		{
			first = mid + 1;
			remaining = remaining - (step + 1);
		}
		else
		{
			remaining = step;
		}
	}

	if (first != end && *first == key)
	{
		return first;
	}
	return end;
}

std::vector<int>::iterator binary_search_v1(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end,
	std::vector<int>::value_type key);

#ifdef VIS
const enum Color
{
	COLOR_NORMAL = 0x0F,
	COLOR_FIRST = 0x0B,
	COLOR_MID = 0x0D,
	COLOR_FOUND = 0x0A,
	COLOR_LAST = 0x0C,
	COLOR_NOTHING_FOUND = 0x0C
};
inline Color operator|(Color a, Color b)
{
	return static_cast<Color>(static_cast<int>(a) | static_cast<int>(b));
}
inline Color operator<<(Color a, int b)
{
	return static_cast<Color>(static_cast<int>(a) << static_cast<int>(b));
}

//takes a value and a color and prints it colored
template <class T>
void print_colored(T i, Color c)
{
	HANDLE cs_out_hdl = GetStdHandle(STD_OUTPUT_HANDLE);

	//save old
	CONSOLE_SCREEN_BUFFER_INFO old;
	GetConsoleScreenBufferInfo(cs_out_hdl, &old);

	//set color
	SetConsoleTextAttribute(cs_out_hdl, c);
	std::cout << i;

	//reset old
	SetConsoleTextAttribute(cs_out_hdl, old.wAttributes);
}

//Prints a range of values, colores active values
template <class Type_Iterator>
void print_range(Type_Iterator begin, Type_Iterator end, Type_Iterator first, Type_Iterator mid,
	typename Type_Iterator::difference_type remaining)
{
	for (Type_Iterator i = begin; i < end; i++)
	{
		Type_Iterator last = first;
		std::advance(last, remaining - 1);
		if (i == mid)
		{
			if (mid == first)
				print_colored(*i, COLOR_MID | (COLOR_FIRST << 4));
			else
				print_colored(*i, COLOR_MID);
		}
		else if (i == first)
			print_colored(*i, COLOR_FIRST);
		else if (i == last)
			print_colored(*i, COLOR_LAST);
		else
			print_colored(*i, COLOR_NORMAL);

		std::cout << " ";
	}
	std::cout << std::endl;
}

inline void user_input()
{
	std::cout << "Continue?";
	char ch;
	std::cin >> ch;
	std::cout << std::endl;
}

inline void say_hello()
{
	std::cout << "Binary search Visualized" << "\nColor meaning:\n";
	print_colored("Normal\n", COLOR_NORMAL);
	print_colored("First\n", COLOR_FIRST);
	print_colored("Mid\n", COLOR_MID);
	print_colored("Last\n", COLOR_LAST);
	print_colored("Found\n\n", COLOR_FOUND);
}

template <class Type_Iterator>
Type_Iterator binary_search_visualized(Type_Iterator first, Type_Iterator end, typename Type_Iterator::value_type key)
{
	say_hello();

	Type_Iterator begin = first;
	Type_Iterator mid;

	typename Type_Iterator::difference_type remaining, step;
	remaining = std::distance(first, end);

	while (remaining > 0)
	{
		step = remaining / 2;
		mid = first;
		std::advance(mid, step);

		//print
		print_range(begin, end, first, mid, remaining);
		user_input();
		//

		if (key > *mid)
		{
			std::advance(mid, 1);
			first = mid;
			remaining = remaining - (step + 1);
		}
		else
		{
			remaining = step;
		}
	}

	//print
	print_range(begin, end, first, mid, remaining);
	//
	if (first != end && *first == key)
	{
		//print
		print_colored(("\nFound: " + std::to_string(*first)), COLOR_FOUND);
		//
		return first;
	}
	print_colored("\nNothing Found", COLOR_NOTHING_FOUND);
	return end;
}
#endif // VIS


