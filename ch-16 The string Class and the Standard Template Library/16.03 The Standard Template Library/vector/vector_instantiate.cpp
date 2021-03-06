/* 20210306 19:29, zyj, GuangDong*/
// vector_instantiate.cpp -- how to get a vector object
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T = vector<uint32_t> >
void vector_list(const T & t, const string & info = "vector")
{
	uint32_t i, size = t.size();
	cout << info;
	for(i = 0; i < size; i++)
		  cout << t[i] << " ";
	cout << endl;
}

/** 2D*/
template <class T = int >
void vector_list(const vector<vector<T> > &t, 
			const string & info = "vector<vector<int> >")
{
	uint32_t i, j, sizei = t.size(), sizej;
	cout << info << endl;
	for(i = 0; i < sizei; i++)
	{
		sizej = t[i].size();
		for(j = 0; j < sizej; j++)
		  cout << t[i][j] << " ";
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
	vector_list(ratings, "ratings : ");

	uint32_t n;
	cout << "enter an integer: ";
	cin >> n;
	vector<double> scores(n, 9.15); // a vector of n doubles and set each to 9.15
	vector_list(scores, "scores : ");

	/** initialize from an array*/
	vector<string> months1(months, months + 12);
	vector_list(months1, "months1: ");

	/** initialization list */
	vector<uint64_t> lengths = {1, 2, 3, 4, 5};
	vector_list(lengths, "lengths: ");

	/** 5 years*/
	vector<vector<string> >  years(5, months1);
	vector_list(years, "five years:");
}
