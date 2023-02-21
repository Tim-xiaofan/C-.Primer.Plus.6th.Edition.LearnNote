#include <iostream>
using namespace std;

const int INCHES_PER_FOOT = 12; // conversion factor

int main(void) 
{
	int height_inches;
	cout << "Enter your height in inches (e.g. 72): ";
	cin >> height_inches;

	int feet = height_inches / INCHES_PER_FOOT;
	int inches = height_inches % INCHES_PER_FOOT;

	cout << "Your height is " << feet << " feet " << inches << " inches." << endl;

	return 0;
}

