#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>
#include <string>
#include <fstream>
#include <list>

const int TESTCOUNT = 1000;

struct aktie
{
	std::string name;
	double price;
	int amount;
};

void read_index();

class Sell_Record
{
	friend double price(double v, const Sell_Record& r);
	friend class Price;
	double price;
	int units;
public:
	Sell_Record(double p, int u)
		:price(p), units(u) {}
};

double price(double v, const Sell_Record& r)
{
	return v + r.price * r.units;
}

class Price
{
public:
	Price() {}
	double operator()(double v, const Sell_Record& r) const
	{
		return v + r.price * r.units;
	} 
};

void run_test(int tests);
double fnct_vs_fnctclass();

int main()
{
	//run_test(10000);
	std::map<std::string, int> m1;
	m1["hallo"]++;
	m1["hallo"]++;
	m1["bogo"]++;
	m1["lalaa"]++;

	
	for (std::map<std::string, int>::const_iterator i1 = m1.begin();
	i1 != m1.end(); i1++)
	{
		std::cout << i1->first << " : " << i1->second << std::endl;
	}

	read_index();

	char ch;
	std::cin >> ch;
}


void run_test(int tests)
{
	double fnct_class_time = 0;
	for (int i = 0; i < tests; i++)
	{
		if (!(i % (tests / 100)))
			std::cout << i / (tests / 100) + 1 << "%\n";
		fnct_class_time += fnct_vs_fnctclass();
	}

	std::cout
		<< "\nFunction Object is: "
		<< fnct_class_time / tests
		<< "mys. faster in VS (with the given example)\n";
}

//returns a value in mys that represents the time 
//a function_class function is ahead of function
//if negative the function was faster
double fnct_vs_fnctclass()
{
	std::vector<Sell_Record> records;
	std::vector<double> dbls(TESTCOUNT);
	std::vector<int> ints(TESTCOUNT);

	//fill with falues
	std::iota(dbls.begin(), dbls.end(), 0.0);
	std::iota(ints.begin(), ints.end(), 0);

	//shuffle values
	std::random_shuffle(dbls.begin(), dbls.end());
	std::random_shuffle(ints.begin(), ints.end());

	//fill records
	for (int i = 0; i < TESTCOUNT; i++)
	{
		records.push_back(Sell_Record(dbls[i], ints[i]));
	}

	double sum_funct = 0.0;
	double sum_funct_class = 0.0;
	std::vector<double> avrg_funct;
	std::vector<double> avrg_funct_class;

	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	for (int i = 0; i < TESTCOUNT; i++)
	{
		//function
		start = std::chrono::system_clock::now();
		sum_funct = 0.0;
		sum_funct = std::accumulate(records.begin(), records.end(), sum_funct, price);
		end = std::chrono::system_clock::now();
		avrg_funct.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

		//function class
		start = std::chrono::system_clock::now();
		sum_funct_class = 0.0;
		sum_funct_class = std::accumulate(records.begin(), records.end(), sum_funct_class, Price());
		end = std::chrono::system_clock::now();
		avrg_funct_class.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
	}
	double averange_funct = 0;
	averange_funct = std::accumulate(avrg_funct.begin(), avrg_funct.end(), averange_funct) / TESTCOUNT;
	
	double averange_funct_class = 0;
	averange_funct_class = std::accumulate(avrg_funct_class.begin(), avrg_funct_class.end(), averange_funct_class) / TESTCOUNT;
	
	return averange_funct - averange_funct_class;
}

void read_index()
{
	std::list<aktie> aktien;
	std::string file = "aktien.txt";
	std::ifstream istr(file.c_str());

	std::string temp;
	while (temp != "Depot") istr >> temp;
	while (temp != "#")
	{
		aktie akt;
		std::string name;
		istr >> name;
		if (name.size() > 6)
			name.erase(name.begin() + 6, name.end());
		akt.name = name;
		istr >> akt.price;

		while (temp != "Mio.") istr >> temp;
		istr >> akt.amount;
		while (temp != "Depot")
		{
			istr >> temp;
			if (temp == "Depot#")
			{
				temp = "#";
				break;
			}
		}
		aktien.push_back(akt);
	}
	std::cout << "\nAktien:\n";
	for (auto i : aktien)
	{
		if (i.amount > 100)
			std::cout << i.name << "\t|\t" << i.amount << "\tths\t|\t" << i.price << "\tEURO" << std::endl;
		else
			std::cout << i.name << "\t|\t" << i.amount * 1000 << "\tths\t|\t" << i.price << "\tEURO" << std::endl;
	}
}

/* !!DEBUG CODE!!
//function
sum_funct = std::accumulate(records.begin(), records.end(), sum_funct, price);
01295479  push        offset price (0128184Dh)
0129547E  sub         esp,8
01295481  movsd       xmm0,mmword ptr [sum_funct]
01295486  movsd       mmword ptr [esp],xmm0
0129548B  sub         esp,0Ch
0129548E  mov         eax,esp
sum_funct = std::accumulate(records.begin(), records.end(), sum_funct, price);
01295490  mov         dword ptr [ebp-310h],esp
01295496  push        eax
01295497  lea         ecx,[records]
0129549A  call        std::vector<Sell_Record,std::allocator<Sell_Record> >::end (0128172Bh)
0129549F  mov         dword ptr [ebp-418h],eax
012954A5  sub         esp,0Ch
012954A8  mov         ecx,esp
012954AA  mov         dword ptr [ebp-31Ch],esp
012954B0  push        ecx
012954B1  lea         ecx,[records]
012954B4  call        std::vector<Sell_Record,std::allocator<Sell_Record> >::begin (01281122h)
012954B9  mov         dword ptr [ebp-41Ch],eax
012954BF  call        std::accumulate<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Sell_Record> > >,double,double (__cdecl*)(double,Sell_Record const &)> (012812C6h)
012954C4  add         esp,24h
012954C7  fstp        qword ptr [ebp-424h]
012954CD  movsd       xmm0,mmword ptr [ebp-424h]
012954D5  movsd       mmword ptr [sum_funct],xmm0

//function class
sum_funct_class = std::accumulate(records.begin(), records.end(), sum_funct_class, Price());
0129557C  lea         ecx,[ebp-375h]
01295582  call        Price::Price (0128144Ch)
01295587  mov         al,byte ptr [eax]
01295589  movzx       ecx,al
0129558C  push        ecx
0129558D  sub         esp,8
01295590  movsd       xmm0,mmword ptr [sum_funct_class]
01295595  movsd       mmword ptr [esp],xmm0
0129559A  sub         esp,0Ch
0129559D  mov         edx,esp
0129559F  mov         dword ptr [ebp-384h],esp
012955A5  push        edx
012955A6  lea         ecx,[records]
012955A9  call        std::vector<Sell_Record,std::allocator<Sell_Record> >::end (0128172Bh)
012955AE  mov         dword ptr [ebp-418h],eax
012955B4  sub         esp,0Ch
012955B7  mov         eax,esp
012955B9  mov         dword ptr [ebp-390h],esp
012955BF  push        eax
012955C0  lea         ecx,[records]
012955C3  call        std::vector<Sell_Record,std::allocator<Sell_Record> >::begin (01281122h)
012955C8  mov         dword ptr [ebp-41Ch],eax
012955CE  call        std::accumulate<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Sell_Record> > >,double,Price> (0128114Ah)
012955D3  add         esp,24h
012955D6  fstp        qword ptr [ebp-424h]
012955DC  movsd       xmm0,mmword ptr [ebp-424h]
012955E4  movsd       mmword ptr [sum_funct_class],xmm0  
*/