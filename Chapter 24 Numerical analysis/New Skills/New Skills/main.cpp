#include <iostream>
#include <complex>
#define _USE_MATH_DEFINES
#include <math.h>
#include <bitset>

void f(int i, double fpd);
void g();


int main()
{
	typedef std::complex<double> cplxd;

	cplxd z1 = std::polar(2.0, M_PI);
	std::cout << z1 << ", " << abs(z1) << ", " << arg(z1) << std::endl;



	std::cout << std::endl;
	const int max = 50;
	int arr[max];
	std::cout << "sizeof(arr[0]): " << sizeof(arr[0]) << ", sizeof(arr): "
		<< sizeof(arr) << ", max * sizeof(int): " << max * sizeof(int)
		<< "\nsizeof(arr) / sizeof(arr[0]): " << sizeof(arr) / sizeof(arr[0]);

	std::cout << std::endl;


	//f(pow(2, ((sizeof(int)) * 8) - 1) - 1, 0);
	//g();
	errno = 0;
	std::sqrt(-10);
	if (errno != 0)
		std::cerr << "err";

	for (int i = 0; i < 10; i++)
		std::cout << 34 << " ";
	std::cout << "\b";
	char ch;
	std::cin >> ch;
}


void f(int i, double fpd)
{
	std::cout << "i: " << i << std::endl;
	std::cout << "fpd: " << fpd << std::endl;
	char c = i;
	std::cout << "c: " << c << std::endl;
	short s = i;
	std::cout << "s: " << s << std::endl;
	i += 1;
	std::cout << "i: " << i << std::endl;
	long lg = i*i;
	std::cout << "lg: " << lg << std::endl;
	float fps = fpd;
	std::cout << "fps: " << fps << std::endl;
	i = fpd;
	std::cout << "i: " << i << std::endl;
	fps = i;
	std::cout << "fps: " << fps << std::endl;
}

void g()
{
	char ch = 0;
	for (int i = 0; i < 500; i++)
	{
		std::cout << int(ch++) << '\t';
	}
}