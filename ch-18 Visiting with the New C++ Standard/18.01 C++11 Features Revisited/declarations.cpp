/* 20210318 22:35, zyj, GuangDong*/
// declarations.cpp -- C++ 11 declarations
#include <iostream>
#include <array>
#include <vector>

/** particularly usefull for template*/
template<typename T, typename U>
void ef(T t, U u)
{
	decltype(t*u) tu;
}

/** template aliases*/
using itType = 
std::vector<std::string>::iterator;// single

template<typename T>
using arr12 = std::array<T,12>; // template for multiple aliases


int main()
{
	/** auto: according to initialization value type*/
	auto maton = 112; // maton is type int
	auto pt = &maton; // pt is type int *
	double fm(double, int);
	auto pf = fm; // pf is type double (*)(double,int)

	/** decltype: according to expression tye*/
	double x;
	int i;
	decltype(x*i) q; // q same type as x*n, i.e., double
	decltype(&x) pd; // pd same as &x, i.e., double *

	int j = 3;
	int &k = j;
	const int &n = j;
	decltype(n) i1 = j; // i1 type const int &
	decltype(j) i2; // i2 type int
	decltype((j)) i3 = j; // i3 type int &
	decltype(k + 1) i4; // i4 type int
	
	/** Template Aliases: using =*/
	itType it;
	arr12<int> arr12i{0, 1, 2};
	return 0;
}

double fm(double, int)
{
	return 3.14;
}

/** Trailing Return Type*/
template<typename T, typename U>
auto eff(T t, U u) -> decltype(t*u)
{
	return t *u;
}
