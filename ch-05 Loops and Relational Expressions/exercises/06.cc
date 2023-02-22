#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

const int MONTHES_PER_YEAR = 12;
const int YEAR_COUNT = 3;

int main(void)
{
	string month_names[MONTHES_PER_YEAR] = {
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sept",
		"Oct",
		"Nov",
		"Dec"
	};
	array<array<int, MONTHES_PER_YEAR>, YEAR_COUNT> sales;
	int sums[YEAR_COUNT] = {0};
	for(int i = 0; i < YEAR_COUNT; ++i)
	{
		cout << "For " << (i + 1) << " year ---->" << endl;
		for(int j = 0; j < MONTHES_PER_YEAR; ++j)
		{
			cout << "enter worth of " << month_names[j] << " sales: ";
			cin >> sales[i][j];
			sums[i] += sales[i][j];
		}
	}
	for(int i = 0; i < YEAR_COUNT; ++i)
	{
		cout << "total sales for the year" << (i + 1) 
			<< ": " << sums[i] << endl;
	}
	return 0;
}
