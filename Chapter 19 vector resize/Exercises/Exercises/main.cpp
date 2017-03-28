/*
Seems that I was drunk as I programmed prats of it.
*/


#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

template <class T, class V = std::vector<T>>
void vector_add(V& v1, const V& v2); 

template <class T, class V>
V& solve_multipli(const V& v1, const V& v2);

template <class N>
class Number;

template <class N>
class Number
{
public:
	N val;
	Number ()
		:val(N()) {}
	Number (N value)
		:val(value) {}

	bool operator==(const Number& i)
	{
		return val == i.val;
	}

	bool operator!=(const Number& i)
	{
		return val != i.val;
	}

	Number& operator+=(const Number& i)
	{
		val += i.val;
		return *this;
	}
	Number& operator-=(const Number& i)
	{
		val -= i.val;
		return *this;
	}
	Number& operator/=(const Number& i)
	{
		val /= i.val;
		return *this;
	}
	Number& operator*=(const Number& i)
	{
		val *= i.val;
		return *this;
	}
};
template <class N>
inline Number<N> operator+(Number<N> lhs, const Number<N>& rhs)
{
	return lhs += rhs;
}

template <class N>
inline Number<N> operator%(const Number<N>& lhs, const int rhs)
{
	N a = lhs.val;
	int m = rhs;

}

template <class N>
std::ostream& operator<<(std::ostream& ostr, const Number<N>& p)
{
	ostr << p.val;
	return ostr;
}

template <class N>
std::istream& operator>>(std::istream& istr, Number<N>& p)
{
	istr >> p.val;
	return istr;
}

template <class L, class R>
struct Pair
{
	L left;
	R right;

	Pair() {}
	Pair(L l, R r)
		:left(l), right(r){}
}; 

template <class L, class R>
std::ostream& operator<<(std::ostream& ostr, const Pair<L,R>& p)
{
	ostr << "(" << p.left << "|" << p.right << ")";
	return ostr;
}

struct Point
{
	int x;
	int y;
	Point ()
		:x(0), y(0) {}
	Point (int x, int y)
		:x(x), y(y) {}

	Point& operator+=(const Point& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& ostr, const Point& p)
{
	ostr << "(" << p.x << "|" << p.y << ")";
	return ostr;
}

inline Point operator+(Point lhs, const Point& rhs)
{
	lhs += rhs;
	return lhs;
}

int main()
{
	try
	{
		/*E1 2
		std::vector<int> v1(10, 2);
		std::vector<int> v2(10, 3);
		vector_add<int>(v1, v2);

		std::vector<Point> v3(10, Point(2,9));
		std::vector<Point> v4(10, Point(4,6));
		vector_add<int>(v3, v4);
		std::cout << "vector_add()" << std::endl;
		for (int i = 0; i < v1.size(); i++)
		{
			std::cout << v1[i] << std::endl;
		}
		for (int i = 0; i < v2.size(); i++)
		{
			std::cout << v3[i] << std::endl;
		}

		std::cout << "solve_multipli()" << std::endl;
		std::vector<int> resultsv1v2(solve_multipli<int>(v1, v2));
		for (int i = 0; i < resultsv1v2.size(); i++)
		{
			std::cout << resultsv1v2[i] << std::endl;
		}
		*/
		/*E3
		std::vector<Pair<char, int>> symbol_table(10);
		for (int i = 0; i < symbol_table.size(); i++)
		{
			symbol_table[i] = Pair<char, int>('a' + i, i);
		}
		for (auto item : symbol_table)
		{
			std::cout << item << std::endl;
		}
		*/

		Number<int> i1(1);
		Number<double> i2(2.0);

		std::cout << "i1: " << i1 << "\ni2; " << i2 << std::endl;
		std::cin >> i1 >> i2;
		std::cout << "i1: " << i1 << "\ni2; " << i2 << std::endl;
		
		std::cout << "\nMod\n";
		std::cout << "i1: " << i1 % 5 << "\ni2; " << i2 % 5 << std::endl;


	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	char ch;
	std::cin >> ch;
}

//E1
template <class T, class V>
void vector_add(V& v1, const V& v2)
{
	if (v1.size() != v2.size())
		throw std::runtime_error("f()\nvector size does not match");
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] += v2[i];
	}
}

//E2
template <class T, class V>
V& solve_multipli(const V& v1, const V& v2)
{
	if (v1.size() != v2.size())
		throw std::runtime_error("f()\nvector size does not match");
	std::auto_ptr<V> results(new V(v1.size()));
	for (int i = 0; i < v1.size(); i++)
	{
		(*results)[i] = v1[i] * v2[i];
	}
	return *(results.release());
}