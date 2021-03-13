/* 20210313 16:44, zyj, GuangDong*/
//initializer_list.cpp -- usage of initializer_list template
#include <iostream>
#include <vector>
#include <valarray>
#include <set>
#include <map>
#include <memory> /** for shared_ptr*/

template <class T> 
void show(const T &t, const std::string & info = "container : ");

template <class val> 
void show(const std::valarray<val> &t, const std::string & info = "valarray : ");

template <class key, class val> 
void show(const std::multimap<key, val> &t, const std::string & info);

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

#define CITIES	{\
	Pair(415, "San Francisco"),\
	Pair(415, "San Francisco1"),\
	Pair(510, "Oakland"),\
	Pair(718, "Brooklyn"),\
	Pair(718, "Staten Island"),\
	Pair(415, "San Rafael"),\
	Pair(510, "Berkeley")}\


int main()
{
	using namespace std;
	vector<double> payments {45.99, 39.23, 19.95, 89.01};
	valarray<double> payments1 = {3.14, 2.71, 9.8, 6.67, 1.61};
	set<double> payments2 = {6.59, 56.92, 8.9, 76.98, -15.03};
	multimap<int, string> payments3 = CITIES;
	shared_ptr<double> spd {new double(25.23)}; // ok to use {} instead of ()
	vector<int> vi{10};/** use initializer_list, one element set to 10*/
	vector<int> vi1(10);/** 10 uninitialized elements*/
	//vector<int> values = {10, 8, 5.5}; // narrowing, compile-time error
	vector<int> values = {10, 8, (int)5.5};
	
	show(payments, "payments : ");
	show(payments1, "payments1 : ");
	show(payments2, "payments2 : ");
	show(payments3, "payments3 : ");
	show(vi, "vi : ");
	show(vi1, "vi1 : ");
	cout << "*spd == " << *spd << endl;
}

template <class T> 
void show(const T &t, const std::string & info)
{
	class T::const_iterator it;
	std::cout << info;
	for(it = t.begin(); it != t.end(); it++)
	  std::cout << *it << " ";
	std::cout << std::endl;
}

template <class val> 
void show(const std::valarray<val> &t, const std::string & info)
{
	std::size_t i;
	std::cout << info;
	for(i = 0; i < t.size(); i++)
	  std::cout << t[i] << " ";
	std::cout << "\n";
}

template <class key, class val> 
void show(const std::multimap<key, val> &t, const std::string & info)
{
	class std::multimap<key, val>::const_iterator it;
	std::cout << info;
	for(it = t.begin(); it != t.end(); it++)
	  std::cout << "(" << it->first << ", " 
		  << it->second <<") ";
	std::cout << std::endl;
}
