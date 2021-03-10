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
	(1, "January"),
	(2, "February"),
	(3, "March"),
	(4, "April"),
	(5, "May"),
	(6, "June"),
	(7, "July"),
	(8, "Aguest"),
	(9, "September"),
	(10, "October"),
	(11, "November"),
	(12, "December")
};


int main()
{
	/** key type = int, value type = string*/
	multimap<int, string> codes;
}
