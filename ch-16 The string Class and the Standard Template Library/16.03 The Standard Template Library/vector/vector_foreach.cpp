/* 20210307 10:39, zyj, GuangDong*/
// vector_foreach.cpp -- usage of for_each
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
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

template <class T>
void buildint_show(const T &t)
{
	cout << t << " ";
}

int main()
{
	vector<uint32_t> ratings(5); // a vector of 5 ints
	vector<uint32_t>::
		iterator pi = ratings.begin();
	*pi++ = 233;
	*pi = 2333;
	cout << "ratings : ";
	for_each(ratings.begin(), ratings.end(), buildint_show<uint32_t>);
	cout << endl;

	uint32_t n;
	cout << "enter an integer: ";
	cin >> n;
	vector<double> scores(n, 9.15); // a vector of n doubles and set each to 9.15
	cout << "scores : ";
	for_each(scores.begin(), scores.end(), buildint_show<double>);
	cout << endl;
	scores.erase(scores.begin(), scores.begin() + 2);
	cout << "after erase [0,2), scores: ";
	for_each(scores.begin(), scores.end(), buildint_show<double>);
	cout << endl;

	/** initialize from an array*/
	vector<string> months1(months, months + 12);
	cout << "months1: ";
	for_each(months1.begin(), months1.end(), buildint_show<string>);
	cout << endl;

	/** initialization list */
	vector<uint64_t> lengths = {1, 2, 3, 4, 5};
	cout << "lengths: ";
	for_each(lengths.begin(), lengths.end(), buildint_show<uint64_t>);
	cout << endl;

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
