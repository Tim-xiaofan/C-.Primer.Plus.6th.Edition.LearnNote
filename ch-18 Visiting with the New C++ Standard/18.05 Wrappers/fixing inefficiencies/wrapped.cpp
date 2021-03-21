/* 20210321 19:53, zyj, GuangDong*/
//wrapped.cpp -- using a function wrapper as an argument
#include "somedefs.h"
#include <iostream>
#include <functional>

double dub(double x) {return 2.0*x;}
double square(double x) {return x*x;}

int main()
{
	using std::cout;
	using std::endl;
	using std::function;

	double y = 1.21;
	//function<double(double)> ef1 = dub;
	//function<double(double)> ef2 = square;
	//function<double(double)> ef3 = Fq(10.0);
	//function<double(double)> ef4 = Fp(10.0);
	//function<double(double)> ef5 = [](double u) {return u*u;};
	//function<double(double)> ef6 = [](double u) {return u+u/2.0;};
	typedef function<double(double)> fdd; // simplify the type declaration
	cout << "Function pointer dub:\n";
	cout << " " << use_f(y, fdd(dub)) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f(y, fdd(square)) << endl;
	cout << "Function object Fp:\n";
	cout << " " << use_f(y, fdd(Fq(10.0))) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f(y, fdd(Fp(10.0))) << endl;
	cout << "Lambda expression 1:\n";
	cout << " " << use_f(y, fdd([](double u) {return u * u;})) << endl;
	cout << "Lambda expression 2:\n";
	cout << " " << use_f(y,fdd([](double u) {return u + u / 2.0;})) << endl;
	return 0;
}
