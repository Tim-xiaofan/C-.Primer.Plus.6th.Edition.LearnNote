/* 20210310 21:28, zyj, GuangDong*/
// function_likely.cpp -- a function object
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

class Linear
{
	private:
		double slope; /** 斜率*/
		double y0;
	public:
		Linear(double sl_ = 1, double y_ = 0)
			: slope(sl_), y0(y_) {}
		double operator()(double x) {return y0 + slope * x; }
};

/** for build-in and string*/
template <class T>
class Show
{
	public:
		void operator()(T & t){std::cout << t << " ";}
};

/** also work*/
/** for build-in and string*/
template <class T>
void Show1(T & t){std::cout << t << " ";}

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
	Linear f1;
	Linear f2(2.5, 10.0);
	double y1 = f1(12.5); // right-hand side is f1.operator()(12.5)
	double y2 = f2(0.4);/** that is function like*/

	cout << "y1 = " << y1 << endl;
	cout << "y2 = " << y2 << endl;

	vector<string> months1(months, months + 12);
	cout << "Show : ";
	for_each(months1.begin(), months1.end(), Show<string>());
	cout << endl;
	
	cout << "Show1 : ";
	for_each(months1.begin(), months1.end(), Show1<string>);
	cout << endl;
}
