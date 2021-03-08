/* 20210308 21:08, zyj, GuangDong*/
// istream_iterator.cpp -- usage of for_each
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>

using namespace std;

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


int main()
{
	vector<int> dice(10);
	cout << "enter 10 integer:\n";
	copy(istream_iterator<int, char>(cin), 
				istream_iterator<int, char>(), 
				dice.begin());
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
}
