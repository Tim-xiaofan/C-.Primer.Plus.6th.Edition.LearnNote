/* 20210311 20:34, zyj, GuangDong*/
// adaptable_adapter.cpp -- using a predefined functors
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
		typedef T first_argument_type;
		typedef T second_argument_type;
		typedef T result_type;
		T operator()(T & t1, T & t2) {return (t1 + t2) / 2;}
};

int main()
{
	Mean<double> f2;

	binder1st<Mean<double> > f1 = bind1st(f2, 2.5);
	//cout << f1;
	return 0;
}
