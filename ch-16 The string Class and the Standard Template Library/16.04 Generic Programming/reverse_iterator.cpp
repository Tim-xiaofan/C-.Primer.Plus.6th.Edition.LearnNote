/* 20210308 22:01, zyj, GuangDong*/
// reverse_iterator.cpp -- usage of reverse iterator
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>
#include <cstdint>

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
	int casts[10] = {6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5};
	vector<int> dice(casts, casts + 10);
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "display in reverse order:\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout <<"Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
	  cout << *ri << ' ';
	cout << endl;
	cout << "*dice.rbegin() " << *dice.rbegin() <<endl;
	cout << "*dice.rendn() " << *dice.rend() <<endl;
	cout << "*(dice.rendn() - 1) " << *(dice.rend() - 1) <<endl;
}
