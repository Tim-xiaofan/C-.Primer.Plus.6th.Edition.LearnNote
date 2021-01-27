/*20210126 20:58,zyj,GuangDong*/
// stock00.cpp -- implementing the Stock class
// version 00
#include <iostream>
#include "stock00.h"

int main()
{
	const int STKS = 4;
	Stock stocks[STKS] = 
	{
		Stock("NanoSmart", 12.5, 20),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	return 0;
}
