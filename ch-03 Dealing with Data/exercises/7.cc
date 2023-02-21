#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

const double MILES_PER_100KM = 62.14;
const double LITERS_PER_GALLON = 3.875;

int main(void) 
{
	cout << "Enter European style (liters per 100 kilometers): ";
	double european;
	cin >> european;

	double tmp = (european / LITERS_PER_GALLON) / MILES_PER_100KM;
	cout << 1 / tmp << " mpg( U.S. style of miles per gallon)" << endl;
	return 0;
}

