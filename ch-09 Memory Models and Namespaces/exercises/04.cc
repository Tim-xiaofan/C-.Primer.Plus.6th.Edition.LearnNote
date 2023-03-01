#include <iostream>
#include "04h.h"

int main(void)
{
	using namespace SALES;
	Sales s1, s2;
	setSales(s1);
	showSales(s1);

	double ar[] = {2.72, 3.14, 0.78, 5.56};
	setSales(s2, ar, 4);
	showSales(s2);
	return 0;
}
