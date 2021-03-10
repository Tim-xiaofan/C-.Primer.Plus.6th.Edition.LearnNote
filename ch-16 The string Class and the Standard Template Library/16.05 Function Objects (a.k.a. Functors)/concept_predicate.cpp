/* 20210310 22:12, zyj, GuangDong*/
// concept_predicate.cpp -- usage of predicate
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>
#include <list>

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

/** binary predicate*/
template <class T>
bool decrease(const T & t1, const T &t2)
{
	if(t1 < t2) return false;
	return true;
}

/** flexiable cutt-off value and a predicate*/
template<class T>
class TooBig
{
	private:
		T cutoff;
	public:
		TooBig(const T & t) : cutoff(t) {}
		bool operator()(const T & v) { return v > cutoff; }
};

int main()
{
	vector<string> months1(months, months + 12);
	cout<<"months1 : ";
	for_each(months1.begin(), months1.end(), Show<string>());
	cout << endl;

	sort(months1.begin(), months1.end(), decrease<string>);
	cout<<"after sort in decrease, months1 : ";
	for_each(months1.begin(), months1.end(), Show<string>());
	cout << endl;
	
	sort(months1.begin(), months1.end());
	cout<<"after sort in increase, months1 : ";
	for_each(months1.begin(), months1.end(), Show<string>());
	cout << endl;

	
	list<int> scores = {78, 69, 120, 119, 56, 99, 88, 70};
	
	cout<<"scores : ";
	for_each(scores.begin(), scores.end(), Show<int>());
	cout << endl;

	scores.remove_if(TooBig<int>(100));
	cout<<"after rm > 100, scores : ";
	for_each(scores.begin(), scores.end(), Show<int>());
	cout << endl;
}
