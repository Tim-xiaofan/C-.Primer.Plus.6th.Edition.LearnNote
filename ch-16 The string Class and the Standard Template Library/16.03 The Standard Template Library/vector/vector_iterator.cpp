/* 20210306 19:29, zyj, GuangDong*/
// vector_iterator.cpp -- usage of iteartor
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T = int >
void vector_list(const vector<T> & t, const string & info = "vector")
{
	//typename std::list< KRect<T> >::iterator i;
	typename std::vector<T>::const_iterator pt;/** pt is an iterator, pointer like */
	cout << info;
	for(pt = t.begin(); pt != t.end(); pt++)
		  cout << *pt << " ";
	cout << endl;
}

/** 2D*/
template <class T = int >
void vector_list(const vector<vector<T> > &t, 
			const string & info = "vector<vector<int> >")
{
	typename std::vector<vector<T> >::const_iterator pout; /** out iterator*/
	typename std::vector<T>::const_iterator pin; /** in iterator*/

	cout << info << endl;
	for(pout = t.begin(); pout != t.end(); pout++)
	{
		for(pin = (*pout).begin(); pin != (*pout).end(); pin++)
		  cout << *pin << " ";
		cout << endl;
	}
}

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
	vector<uint32_t> ratings(5); // a vector of 5 ints
	vector<uint32_t>::
		iterator pi = ratings.begin();
	*pi++ = 233;
	*pi = 2333;
	vector_list(ratings, "ratings : ");

	uint32_t n;
	cout << "enter an integer: ";
	cin >> n;
	vector<double> scores(n, 9.15); // a vector of n doubles and set each to 9.15
	vector_list(scores, "scores : ");
	scores.erase(scores.begin(), scores.begin() + 2);
	vector_list(scores, "after erase [0,2), scores: ");

	/** initialize from an array*/
	vector<string> months1(months, months + 12);
	vector_list(months1, "months1: ");

	/** initialization list */
	vector<uint64_t> lengths = {1, 2, 3, 4, 5};
	vector_list(lengths, "lengths: ");

	/** 5 years*/
	vector<vector<string> >  years(5, months1);
	vector_list(years, "five years:");
	
	months1.erase(months1.begin() + 5, months1.begin() + 7);
	vector_list(months1, "after erase [5,7), months1: ");

	/** insert*/
	vector<char> chl = {'a', 'b', 'c', 'd', 'e'};
	vector<char> chu = {'A', 'B', 'C', 'D', 'E'};
	chl.insert(chl.begin() + 1, chu.begin() + 1, chu.end());
	vector_list(chl, "chl: ");
}
