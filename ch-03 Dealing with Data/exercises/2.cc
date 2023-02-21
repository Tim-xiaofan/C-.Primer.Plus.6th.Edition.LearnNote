#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int INCHES_PER_FOOT = 12; // conversion factor
const double POUNDS_PER_KILOGRAM = 2.2;
const double INCHES_PER_METER = 0.0254;

int main(void) 
{
	int height_feet;
	cout << "Enter foot part of your height: ";
	cin >> height_feet;

	int height_inches;
	cout << "Enter inch part of your height: ";
	cin >> height_inches;

	double weight_pounds;
	cout << "Enter pounds of your weight: ";
	cin >> weight_pounds;

	int height_total_inches = height_inches + INCHES_PER_METER * height_feet;
	double height_meters = height_total_inches * INCHES_PER_METER;
	cout << "height_meters: " << height_meters << endl;
	double weight_kilograms = weight_pounds / POUNDS_PER_KILOGRAM;
	cout << "weight_kilograms: " << weight_kilograms << endl;

	double BMI = weight_kilograms / (height_meters * height_meters);
	cout << "BMI: " << BMI << endl;
	return 0;
}

