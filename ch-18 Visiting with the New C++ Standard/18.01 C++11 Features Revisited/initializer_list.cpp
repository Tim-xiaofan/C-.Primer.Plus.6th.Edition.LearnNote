/* 20210318 22:09, zyj, GuangDong*/
// initializer_list.cpp -- C++ 11 template
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iterator>

double sum(std::initializer_list<double> il);

int main()
{
	using namespace std;
	
	ostream_iterator<int, char> out(cout, " ");

	vector<int> a1(10); // uninitialized vector with 10 elements
	cout << "a1 : ";
	copy(a1.begin(), a1.end(), out);
	cout << endl;

	vector<int> a2{10}; // initializer-list, a2 has 1 element set to 10
	cout << "a2 : ";
	copy(a2.begin(), a2.end(), out);
	cout << endl;

	vector<int> a3{4,6,1}; // 3 elements set to 4,6,1
	cout << "a3 : ";
	copy(a3.begin(), a3.end(), out);
	cout << endl;

	double total = sum({2.5,3.1,4}); // 4 converted to 4.0
	cout << "total = " << total << endl;
}

double sum(std::initializer_list<double> il)
{
	double tot = 0;
	std::initializer_list<double>::const_iterator p;
	for (p = il.begin(); p !=il.end(); p++)
	  tot += *p;
	return tot;
}
