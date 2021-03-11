/* 20210311 08:50, zyj, GuangDong*/
// predefined_functors.cpp -- using a predefined functors
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#define LIM  5

using namespace std;

template <class T>
class Sqrt
{
	public:
		T operator()(T& t) {return sqrt(t);}
};

template <class T>
class Mean
{
	public:
		T operator()(T & t1, T & t2) {return (t1 + t2) / 2;}
};

int main()
{
	double arr1[LIM] = {36, 39, 42, 45, 48},
		   arr2[LIM] = {32, 95, 60, 139, 46};

	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	ostream_iterator<double, char> out(cout, " ");

	cout << "gr8 : ";
	copy(gr8.begin(), gr8.end(), out);
	cout << endl;
	cout << "m8 : ";
	copy(m8.begin(), m8.end(), out);
	cout << endl;

	transform(gr8.begin(), gr8.end(), gr8.begin(), Sqrt<double>());
	cout << "after sqrt, gr8 : ";
	copy(gr8.begin(), gr8.end(), out);
	cout << endl;

	cout << "mean of gr8 and m8 :";
	transform(gr8.begin(), gr8.end(), m8.begin(), out, Mean<double>());
	cout << endl;
	
	cout << "sum of gr8 and m8 :";
	transform(gr8.begin(), gr8.end(), m8.begin(), out, plus<double>());
	cout << endl;
}
