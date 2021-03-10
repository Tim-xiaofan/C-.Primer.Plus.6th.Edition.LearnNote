/* 20210310 12:51, zyj, GuangDong*/
// multimap.cpp -- usage of multimap container
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

const pair<const int, string> months[12]=
{
	pair<const int, string>(1, "January"),
	pair<const int, string>(2, "February"),
	pair<const int, string>(3, "March"),
	pair<const int, string>(4, "April"),
	pair<const int, string>(5, "May"),
	pair<const int, string>(6, "June"),
	pair<const int, string>(7, "July"),
	pair<const int, string>(8, "Aguest"),
	pair<const int, string>(9, "September"),
	pair<const int, string>(10, "October"),
	pair<const int, string>(11, "November"),
	pair<const int, string>(12, "December")
};


int main()
{
	/** key type = int, value type = string*/
	multimap<int, string> codes;
	/** single insert*/
	codes.insert(pair<const int, string>(13, "unkown"));
	codes.insert(pair<const int, string>(13, "unkown1"));
	codes.insert(pair<const int, string>(13, "unkown2"));
	/** range insert*/
	codes.insert(months, months + 12);

	/** range*/
	pair<multimap<int, string>::iterator, 
		multimap<int, string>::iterator> range = codes.equal_range(13);

	cout << "months with id 13 : ";
	std::multimap<int, string> ::iterator it;
	for(it = range.first; it != range.second; it ++)
	  cout << it->second << " ";
	cout << endl;
}
