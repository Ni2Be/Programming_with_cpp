#include "Binsearch.h"

#include <iostream>


std::vector<int>::iterator binary_search_v1(std::vector<int>::iterator first, std::vector<int>::iterator end, std::vector<int>::value_type key)
{
	std::vector<int>::iterator begin = first;
	std::vector<int>::iterator not_found = end;

	std::vector<int>::iterator::difference_type remaining, step;
	remaining = std::distance(first, end);
	
	std::vector<int>::iterator mid;
	
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
#ifdef _DEBUG
	std::cerr << "\natt: " << std::distance(begin, first) << std::endl;
#endif // _DEBUG
	return not_found;
}


/*
std::iterator_traits is the type trait class that provides uniform interface to the 
properties of Iterator types. This makes it possible to implement algorithms only in terms of iterators.

The class defines the following types:

difference_type - a type that can be used to identify distance between iterators
value_type - the type of the values that can be obtained by dereferencing the iterator. 
This type is void for output iterators.
pointer - defines a pointer to the type iterated over (value_type)
reference - defines a reference to the type iterated over (value_type)
iterator_category - the category of the iterator. Must be one of iterator category tags.

The template can be specialized for user-defined iterators so that the information about the 
iterator can be retrieved even if the type does not provide the usual typedefs.
*/


