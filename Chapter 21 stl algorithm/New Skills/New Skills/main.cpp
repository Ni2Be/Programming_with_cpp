#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <memory>

const int TESTCOUNT = 1000;

//SHARE TEST
struct Share;
std::list<Share>& read_index(std::string);
void share_list_to_maps(std::list<Share>&, 
	std::map<std::string, int>& amounts, 
	std::map<std::string, double>& prices);
void run_map_test();


//Function vs function-object test
class Sell_Record;
class Price;
void run_functobjct_test(int tests);
double fnct_vs_fnctclass();
double price(double v, const Sell_Record& r);


//MAIN
int main()
{
	run_functobjct_test(10000);
	
	run_map_test();

	char ch;
	std::cin >> ch;
}

//Function vs function-object test
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

class Price
{
public:
	Price() {}
	double operator()(double v, const Sell_Record& r) const
	{
		return v + r.price * r.units;
	}
};

double price(double v, const Sell_Record& r)
{
	return v + r.price * r.units;
}

void run_functobjct_test(int tests)
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


//SHARE TEST
struct Share
{
	std::string name;
	double price;
	int amount;
};

void run_map_test()
{
	std::list<Share> shares = read_index("aktien.txt");

	std::map<std::string, int> amounts;
	std::map<std::string, double> prices;
	share_list_to_maps(shares, amounts, prices);

	for (std::map<std::string, int>::const_iterator iA = amounts.begin();
	iA != amounts.end(); iA++)
	{
		std::cout << iA->first << "\t Price: " << prices[iA->first]
			<< "\t Amount: " << iA->second << std::endl;
	}
}

std::list<Share>& read_index(std::string file)
{
	/*	EXCAMPLE DATA:

	THYSSENKRUPP 	22,03 €  	-0,42 	-1,89%
	Negative Veraenderung
	17:35 	52,4 Mio. 	2,4 Mio. 	Link zum Chart 	News 	Depot
	VOLKSWAGENVZ 	131,90 €  	+0,15 	+0,11%
	Negative Veraenderung
	17:35 	117,0 Mio. 	882.136 	Link zum Chart 	News 	Depot
	*/
	std::unique_ptr<std::list<Share>> shares(new std::list<Share>);
	std::ifstream istr(file.c_str());
	std::string temp;

	while (temp != "Depot") istr >> temp;
	while (temp != "#")
	{
		//get name
		Share share;
		std::string name;
		istr >> name;
		if (name.size() > 6)
			name.erase(name.begin() + 6, name.end());
		share.name = name;
		
		//get price
		istr >> share.price;
		istr.get();
		double dec = 0.0;
		istr >> dec;
		share.price += dec / 100;

		//get amount
		while (temp != "Mio.") istr >> temp;
		istr >> share.amount;
		if (istr.get() == ',')
		{
			istr >> dec;
			share.amount = share.amount * 1000 + dec * 100;
		}

		//save share
		shares->push_back(share);
		
		//eat useless data
		while (temp != "Depot")
		{
			istr >> temp;
			//End of data should be signed with a "#"
			//after the last depot that should be read 
			//in the txt file
			if (temp == "Depot#")
			{
				temp = "#";
				break;
			}
		}
	}
	return *shares.release();
}

void share_list_to_maps(std::list<Share>& shares,
	std::map<std::string, int>& amounts,
	std::map<std::string, double>& prices)
{
	for (auto share : shares)
	{
		amounts[share.name] += share.amount;
		prices[share.name] += share.price;
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