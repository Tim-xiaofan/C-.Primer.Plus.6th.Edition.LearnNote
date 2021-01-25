/*20210125 12:50,zyj,GuangDong*/

// stock00.cpp -- implementing the Stock class
// version 00
#include <iostream>
#include "stock00.h"

int main()
{
	Stock kate;/** call the constructor implicitly*/
	kate.show(); // the kate object calls the member function
	Stock joe("Alipay", 233, 23.3);/** implicitly*/
	joe.show();
	Stock Tom = Stock("Baidu", 2333, 2.33);/** call the constructor explicitly*/
	Tom.show();
	Stock *Jarray = new Stock("HUAWEI", 23, 0.233);/** new for dynamic memory allocation*/
	Jarray->show();

	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);

	/** object assignment*/
	Stock tmp = joe;/*donot called constructor*/
	tmp.show();

	delete Jarray;
	Jarray = NULL;
	return 0;
}
