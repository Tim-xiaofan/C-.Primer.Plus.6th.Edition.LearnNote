/*20201219 16:31,zyj,GaungDong*/
// address.cpp -- using the & operator to find addresses
#include <iostream>
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;
	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;
	// NOTE: you may need to use unsigned (&donuts)
	// and unsigned (&cups)
	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl;
	cout << "&cups - &donuts = " << (char *)&cups - (char* )&donuts<< endl;
	return 0;
}
