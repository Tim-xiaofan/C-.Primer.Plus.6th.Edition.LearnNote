/* 20210311 08:50, zyj, GuangDong*/
// general_properties.cpp -- General Properties of Algorithms
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#define LIM  6

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
	"August",
	"September",
	"October",
	"November",
	"December"
};

double arr1[LIM] = {28, 29, 30, 35, 38, 59};
double arr2[LIM] = {63, 65, 69, 75, 80, 99};

template <class T>
class out
{
	public:
		ostream_iterator<T, char> 
		get_out(){return ostream_iterator<T, char>(cout, " ");}
};

template <class T>
class Bigger
{
	private:
		T val;
	public:
		Bigger(const T & t){val = t;}
		bool operator()(const T & t)
		{
			if(t > val)
			  cout << t <<" >" << val<< endl;
			return (t > val);
		}
};

int main()
{
	vector<string> months1(months, months + 12);

	/** template<class InputIterator, class OutputIterator>
	  OutputIterator copy(InputIterator first, InputIterator last,
	  OutputIterator result);*/
	std::vector<string>::iterator it1 =  months1.begin(),
		it2 = months1.end();
	cout << "months1 : ";
	copy(it1, it2, out<string>().get_out());
	cout << endl;

	/**template<class ForwardIterator, class T>
	  void replace(ForwardIterator first, ForwardIterator last,
	  const T& old_value, const T& new_value);*/
	replace(it1, it2, string("August"), string("Aug"));
	cout << "after replace \"August\" with \"Aug\", months1 : \n";
	copy(it1, it2, out<string>().get_out());
	cout << endl;

	/** template<class InputIterator, class OutputIterator, class T>
	  OutputIterator replace_copy(InputIterator first, InputIterator last,
	  OutputIterator result,const T& old_value, const T& new_value);*/
	cout << "after replace \"Aug\" with \"August\", months1 : \n";
	replace_copy(it1, it2, out<string>().get_out(),
				string("Aug"), string("August"));
	cout << endl;

	/** template<class ForwardIterator, class Predicate class T>
	  void replace_if(ForwardIterator first, ForwardIterator last,
	  Predicate pred, const T& new_value);*/
	replace_if(it1, it2, Bigger<string>("April"), string("unkown"));
	cout << "after replace if > \"April\" with \"unkown\", months1 : \n";
	copy(it1, it2, out<string>().get_out());
	cout << endl;
}

