/* 20210307 14:02, zyj, GuangDong*/
// vector_randomshuffle.cpp -- usage of for_each
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>

using namespace std;

template <class T = int >
void vector_list(const vector<T> & t, const string & info = "vector")
{
	//typename std::list< KRect<T> >::iterator i;
	typename std::vector<T>::const_iterator pt;/** pt is an iterator, pointer like */
	cout << info;
	for(pt = t.begin(); pt != t.end(); pt++)
		  cout << *pt << " ";
	cout << endl;
}

/** 2D*/
template <class T = int >
void vector_list(const vector<vector<T> > &t, 
			const string & info = "vector<vector<int> >")
{
	typename std::vector<vector<T> >::const_iterator pout; /** out iterator*/
	typename std::vector<T>::const_iterator pin; /** in iterator*/

	cout << info << endl;
	for(pout = t.begin(); pout != t.end(); pout++)
	{
		for(pin = (*pout).begin(); pin != (*pout).end(); pin++)
		  cout << *pin << " ";
		cout << endl;
	}
}

const string months[12]=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Aguest",
	"September",
	"October",
	"November",
	"December"
};

const int32_t mess[10] = {1, 99, 22, 0, 5, 6, 999, 16, 7788, 9527};

template <class T>
void buildint_show(const T &t)
{
	cout << t << " ";
}

template <class T>
bool buildint_decrease(const T& t1, const T& t2)
{
	if(t1 < t2)
	  return false; /** wrong order*/
	return true;
}

int main()
{
	/** initialize from an array*/
	vector<string> months1(months, months + 12);
	cout << "months1: ";
	for(string x : months1)
	  cout << x << " ";
	cout << endl;

	for(string & x : months1)
	  x = "null";
	vector_list(months1, "after alter, months1: ");
}
