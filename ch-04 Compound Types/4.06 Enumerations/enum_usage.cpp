/*20201219 15:45,zyj,GuangDong*/
// enum_usage.cpp
#include <iostream>
#include <cstring>
using namespace std;
enum pectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
int main(int argc, char* argv[])
{
	cout << "sizeof(enum pectrum) = " << sizeof(enum pectrum) << endl;
	enum pectrum band; // band a variable of type spectrum
	band = blue; // valid, blue is an enumerator
	cout << band << endl;
	band = 2000; // invalid;error: invalid conversion from ‘int’ to ‘pectrum’
	int i = 2000;
	band = (enum pectrum)i; /*success: not narrow*/
	cout << band << endl;
	band = orange; // valid
	++band; // not valid, ++ discussed in Chapter 5
	band = orange + red; // not valid, but a little tricky
	int color = blue; // valid, spectrum type promoted to int
	band = 3; // invalid, int not converted to spectrum
	color = 3 + red; // valid, red converted to int

	enum bits{one = 1, two = 2, four = 4, eight = 8};
	bits myflag;
	myflag = bits(6); // valid, because 6 is in bits range
	myflag = (bits)6;
	return 0;
}
