/* 20210311 20:41, zyj, GuangDong*/
// funadap.cpp -- using function adapters
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void Show(double);
const int LIM = 6;
const int LIM2 = 7;

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
	using namespace std;
	double arr1[LIM] = {28, 29, 30, 35, 38, 59};
	double arr2[LIM2] = {63, 65, 69, 75, 80, 99, 48};
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM2);
	cout.setf(ios_base::fixed);
	cout.precision(1);
	cout << "gr8:\t\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	cout << "m8: \t\t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;

	vector<double> sum(LIM2);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(),
				plus<double>());
	cout << "sum:\t\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;

	vector<double> prod(LIM);
	transform(gr8.begin(), gr8.end(), prod.begin(),
				bind1st(multiplies<double>(), 2.5));
	cout << "prod:\t\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;

	ostream_iterator<double, char> out(cout, " ");
	cout << "gr8 - m8 :\t ";
	transform(gr8.begin(), gr8.end(), m8.begin(), out, minus<double>());
	cout << endl;
	return 0;
}

void Show(double v)
{
	std::cout.width(6);
	std::cout << v << ' ';
}
