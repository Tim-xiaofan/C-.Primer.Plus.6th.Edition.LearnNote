/*20210125 12:50,zyj,GuangDong*/

// stock00.cpp -- implementing the Stock class
// version 00
#include <iostream>
#include "stock00.h"

int main()
{
	Stock kate, joe;
	kate.acquire("Ali", 9527, 23.3);
	kate.show(); // the kate object calls the member function
	joe.acquire("Baidu", 2748, 233);
	joe.show(); // the joe object calls the member function

	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(300000,40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(300000,0.125);
	fluffy_the_cat.show();
	return 0;
	return 0;
}
