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

int main()
{
	double arr1[LIM] = {36, 39, 42, 45, 48};

	vector<double> gr8(arr1, arr1 + LIM);
	ostream_iterator<double, char> out(cout, " ");
	transform(gr8.begin(), gr8.end(), out, std::tr1::sqrt);
}
