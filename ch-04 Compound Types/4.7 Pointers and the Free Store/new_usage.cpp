/*20201221 08:54,zyj,GuangDong */
// new_usage.cpp -- using the new operator
#include <iostream>
int main()
{
	using namespace std;
	int nights = 1001;
	int * pt = new int; // allocate space for an int
	*pt = 1001; // store a value there
	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;
	double * pd = new double; // allocate space for a double
	*pd = 10000001.0; // store a double there
	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof pd;
	cout << ": size of *pd = " << sizeof(*pd) << endl;
	return 0;
}
/**
 nights value = 1001: location 0xffffcacdb3f4
 int value = 1001: location = 0xaaab1b61ee70
 double value = 1e+07: location = 0xaaab1b61f2a0
 location of pointer pd: 0xffffcacdb3f8
 size of pt = 8: size of *pt = 4
 size of pd = 8: size of *pd = 8
 */
