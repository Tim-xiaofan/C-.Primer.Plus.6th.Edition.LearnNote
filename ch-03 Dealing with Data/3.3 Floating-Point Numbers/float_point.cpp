/* represent float in C++*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	float f1 = 12.34; // floating-point
	f1 = 939001.32; // floating-point
	f1 = 0.00023; // floating-point
	f1 = 8.0; // still floating-point
	f1 =2.52e+8; // can use E or e, + is optional
	f1 =8.33E-4; // exponent can be negative
	f1 =7E5; // same as 7.0E+05
	f1 =-18.32e13; // can have + or - sign in front
	f1 =1.69e12; // 2010 Brazilian public debt in reais
	f1 =5.98E24; // mass of earth in kilograms
	f1 =9.11e-31; // mass of an electron in kilograms
	cout << "sizeof(float):" << sizeof(float) <<endl;
	cout << "sizeof(double):" << sizeof(double) <<endl;
	cout << "sizeof(long double):" << sizeof(long double) <<endl;
	cout << "sizeof(bool):" << sizeof(bool) <<endl;
}

