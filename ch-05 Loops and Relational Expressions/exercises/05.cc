#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int MONTHES_PER_YEAR = 12;

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
	int month_worthes[MONTHES_PER_YEAR];
	int sum = 0;
	for(int i = 0; i < MONTHES_PER_YEAR; ++i)
	{
		cout << "enter worth of " << month_names[i] << " sales: ";
		cin >> month_worthes[i];
		sum += month_worthes[i];
	}
	cout << "total sales for the year: " << sum << endl;
    return 0;
}
