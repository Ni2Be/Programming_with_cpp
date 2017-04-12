#include "vector.h"



//Copy constructor:
not_std::vector::vector(const vector& ref)
	:sz(ref.sz), elem(new double[ref.sz])
{
	copy(ref);
}

//Operator:
not_std::vector& not_std::vector::operator=(const vector& ref)
{
	//should better copy first and delete later
	if (this == &ref)
		return *this;
	delete(elem);
	sz = ref.sz;
	elem = new double[sz];
	copy(ref);
	return *this;
}

double& not_std::vector::operator[](int idx) 
{ 
	return elem[idx];
}

const double& not_std::vector::operator[](int idx) const
{
	return elem[idx];
}

//Private functions:
void not_std::vector::copy(const vector& arg)
{
	for (int i = 0; i < sz; i++)
	{
		elem[i] = arg.elem[i];
	}
}