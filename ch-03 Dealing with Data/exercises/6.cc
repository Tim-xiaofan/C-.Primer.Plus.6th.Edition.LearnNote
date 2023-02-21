#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

int main(void) 
{
	cout << "kilograms you have driven: ";
	double kilograms;
	cin >> kilograms;

	cout << "liters of gasoline you have used: ";
	double liters;
	cin >> liters;

	cout << liters / kilograms * 100.0<< "L/100KM" << endl;
	return 0;
}

