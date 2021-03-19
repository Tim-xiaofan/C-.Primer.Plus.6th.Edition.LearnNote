/* 20210318 22:35, zyj, GuangDong*/
// declarations.cpp -- C++ 11 declarations
#include <iostream>

/** particularly usefull for template*/
template<typename T, typename U>
void ef(T t, U u)
{
	decltype(t*u) tu;
}

int main()
{
	/** auto: according to initialization value type*/
	auto maton = 112; // maton is type int
	auto pt = &maton; // pt is type int *
	double fm(double, int);
	auto pf = fm; // pf is type double (*)(double,int)

	/** decltype: according to expression tye*/
	double x;
	int n;
	decltype(x*n) q; // q same type as x*n, i.e., double
	decltype(&x) pd; // pd same as &x, i.e., double *

	int j = 3;
	int &k = j;
	const int &n = j;
	decltype(n) i1; // i1 type const int &
	decltype(j) i2; // i2 type int
	decltype((j)) i3; // i3 type int &
	decltype(k + 1) i4; // i4 type int

	return 0;
}

double fm(double, int)
{
	return 3.14;
}
