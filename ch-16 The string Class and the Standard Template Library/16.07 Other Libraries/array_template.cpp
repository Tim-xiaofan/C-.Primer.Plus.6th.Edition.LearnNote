/* 20210313 14:10, zyj, GuangDong*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <array>
#include <valarray>
#include <functional>
#include <cmath>

using namespace std;

double arr1[10] = {4, 2.79, 1.44, 2.33, 0, 85.7, 8, -23, 78, 10};
double arr2[10] = {1000.0, 2.0, 3.4, 7.0, 50.0, 1.44, 2.33, 68.5, 85.7, -99.7};

class Log
{
	int _base;
	public:
		enum {two_base, e_base, ten_base};
		Log(int base = e_base):_base(base){}
		double operator()(const double &x)
		{
			switch(_base)
			{
				case two_base: return std::log2(x);
				case ten_base: return std::log10(x);
				case e_base: 
				default:return std::log(x);
			}
		}
};

int main()
{
	vector<double> ved1(arr1, arr1 + 10), ved2(arr2, arr2 + 10), ved3(10);
	array<double, 10> vod1, vod2, vod3;
	valarray<double> vad1(arr1, 10), vad2(arr2, 10), vad3(10);
	ostream_iterator<double, char> out(cout, " ");

	cout << "1 : ";
	copy(arr1, arr1 + 10, out);
	cout << endl;
	cout << "2 : ";
	copy(arr2, arr2 + 10, out);
	cout << endl;

	cout << "ved3 = ved1 + ved2, ved3 : ";
	transform(ved1.begin(), ved1.end(), ved2.begin(), 
				ved3.begin(), plus<double>());
	copy(ved3.begin(), ved3.end(), out);
	cout << endl;
	cout << "ved3 = ved1 * ved2, ved3 : ";
	transform(ved1.begin(), ved1.end(), ved2.begin(), 
				ved3.begin(), multiplies<double>());
	copy(ved3.begin(), ved3.end(), out);
	cout << endl;
	cout << "ved3 = log2(ved1), ved3 : ";
	transform(ved1.begin(), ved1.end(), 
				ved3.begin(), Log(Log::two_base));
	copy(ved3.begin(), ved3.end(), out);
	cout << endl << endl;

	copy(arr1, arr1 + 10, vod1.begin());
	copy(arr2, arr2 + 10, vod2.begin());

	cout << "vod3 = vod1 + vod2, vod3 : ";
	transform(vod1.begin(), vod1.end(), vod2.begin(), 
				vod3.begin(), plus<double>());
	copy(vod3.begin(), vod3.end(), out);
	cout << endl;
	cout << "vod3 = vod1 * vod2, vod3 : ";
	transform(vod1.begin(), vod1.end(), vod2.begin(), 
				vod3.begin(), multiplies<double>());
	copy(vod3.begin(), vod3.end(), out);
	cout << endl;
	cout << "vod3 = loge(vod2), vod3 : ";
	transform(vod2.begin(), vod2.end(), 
				vod3.begin(), Log(Log::e_base));
	copy(vod3.begin(), vod3.end(), out);
	cout << endl << endl;

	/** for template valarray, just use '+'*/
	cout << "vad3 = vad1 + vad2, vad3 : ";
	vad3 = vad1 + vad2;
	/** valarray objects have no member function end and begin */
	copy(begin(vad3), end(vad3), out);/** c++ 11*/
	cout << endl;

	cout << "vad3 = vad1 * vad2, vad3 : ";
	vad3 = vad1 * vad2;
	copy(begin(vad3), end(vad3), out);
	cout << endl;
	
	cout << "vad3 = loge(vad2), vad3 : ";
	vad3 = log(vad2);
	copy(begin(vad3), end(vad3), out);
	cout << endl << endl;
}
