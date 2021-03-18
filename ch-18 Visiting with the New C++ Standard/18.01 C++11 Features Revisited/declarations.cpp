/* 20210318 22:35, zyj, GuangDong*/
// declarations.cpp -- C++ 11 declarations
#include <iostream>

int main()
{
	auto maton = 112; // maton is type int
	auto pt = &maton; // pt is type int *
	double fm(double, int);
	auto pf = fm; // pf is type double (*)(double,int)

	double x;
	int n;
	decltype(x*n) q; // q same type as x*n, i.e., double
	decltype(&x) pd; // pd same as &x, i.e., double *

	return 0;
}

double fm(double, int)
{
	return 3.14;
}
