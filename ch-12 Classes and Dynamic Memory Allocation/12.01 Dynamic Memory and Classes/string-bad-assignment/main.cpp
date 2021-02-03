/** 20210131 21:28,zyj,GuangDong*/
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "stringbad.h"
void callme1(StringBad &); // pass by reference
void callme2(StringBad); // pass by value

int main()
{
	using std::endl;
	{
		StringBad headline1("Celery Stalks at Midnight");
		StringBad knot;
		knot = headline1; // assignment operator invoked
		StringBad metoo = knot; // use copy constructor, possibly assignment, too
	}
	cout << "End of main()\n";
	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "String passed by reference:\n";
	cout << " \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "String passed by value:\n";
	cout << " \"" << sb << "\"\n";
}
