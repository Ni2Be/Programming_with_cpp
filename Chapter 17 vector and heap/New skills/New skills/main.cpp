#include <iostream>
#include <vector>

void size_test();
void ptr_test();

using namespace std;

int main()
{
	//size_test();
	ptr_test();

	char ch;
	cin >> ch;
	return 0;
}



// output of some data sizes
void size_test()
{
	cout << "\nsize of int: " << sizeof(int) << " " << sizeof(2 + 1) << endl;
	cout << "\nsize of double: " << sizeof(double) << " " << sizeof(2.0 + 1) << endl;
	int* iptr = 0;
	cout << "\nsize of int prt: " << sizeof(int*) << " " << sizeof(iptr) << endl;
	double* dptr = 0;
	cout << "\nsize of double prt: " << sizeof(double*) << " " << sizeof(dptr) << endl;
	vector<int> ivec(20, 1);
	cout << "\nsize of int vec: " << sizeof(vector<int>) << " " << sizeof(ivec) << endl;
	vector<double> dvec(20, 1);
	cout << "\nsize of double vec: " << sizeof(vector<double>) << " " << sizeof(dvec) << endl;
}

void ptr_test()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };
	for (int i = -5; i < 3; i++)
	{
		cout << arr1[i] << ", ";
	}
	cout << endl;
	/*
	stack:
	4
	5
	6
	adr
	adr
	1
	2
	3
	*/

	/* same:
	int arr3[3];
	int arr4[3];
	for (int i = 0; i < 3; i++)
		arr3[i] = i + 1;
	for (int i = 0; i < 3; i++)
		arr4[i] = i + 4;
	for (int i = -5; i < 3; i++)
	{
		cout << arr3[i] << ", ";
	}
	*/
}
