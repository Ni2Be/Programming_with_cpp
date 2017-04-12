#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

const int JILLMAX = 1000;
const int JACKMAX = 5000;

void fct();
double* get_from_jack(int& count);
std::vector<double>* get_from_jill();
template <class Iterator>
Iterator get_highest(Iterator first, Iterator end);

int main()
{
	fct();
	char ch;
	std::cin >> ch;
}

void fct()
{
	int jack_count = JACKMAX;
	std::unique_ptr<double> jack_data(get_from_jack(jack_count));
	std::unique_ptr<std::vector<double>> jill_data(get_from_jill());
	
	double* jack_h = get_highest(jack_data.get(), jack_data.get() + jack_count);
	std::vector<double>::iterator jill_h = get_highest(jill_data->begin(), jill_data->end());

	std::cout << "jack first: " << *jack_data.get() << std::endl;
	std::cout << "jill first: " << jill_data->front() << std::endl;

	std::cout << "jack highest: " << *jack_h << std::endl;
	std::cout << "jill highest: " << *jill_h << std::endl;
}

double* get_from_jack(int& count)
{
	double* jack = new double[count];
	for (int i = 0; i < count; i++)
	{
		jack[i] = i * 3;
	}
	std::random_shuffle(jack, jack + count);
	return jack;
}

std::vector<double>* get_from_jill()
{
	std::unique_ptr<std::vector<double>> jill(new std::vector<double>());
	for (int i = 0; i < JILLMAX; i++)
	{
		jill->push_back(i * 2);
	}
	std::random_shuffle(jill->begin(), jill->end());
	return jill.release();
}

template <class Iterator>
Iterator get_highest(Iterator first, Iterator end)
{
	Iterator highest = first;
	while (first != end)
	{
		if (*highest < *first)
			highest = first;
		first++;
	}
	return highest;
}