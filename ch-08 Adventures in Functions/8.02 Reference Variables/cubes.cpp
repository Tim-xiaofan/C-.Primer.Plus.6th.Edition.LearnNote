/*20210110 17:53,zyj,GuangDong*/
// cubes.cpp -- regular and reference arguments
#include <iostream>
double cube(double a);
double refcube(double &ra);
double refcube_const(const double &ra);
void swapr(int &a, int &b);
int main ()
{
	using namespace std;
	double x = 3.0;
	cout << cube(x);
	cout << " = cube of " << x << endl;
	cout << refcube(x);
	cout << " = cube of " << x << endl;
	cout << refcube_const(x);
	cout << " = cube of " << x << endl;
	//double z = refcube(x + 3.0); // cannot not be compile
	double side = 3.0;
	double *pd = &side;
	double &rd = side;
	long edge = 5L;//wrong type
	double lens[4] = { 2.0, 5.0, 10.0, 12.0};
	double c1 = refcube_const(side); // ra is side
	double c2 = refcube_const(lens[2]); // ra is lens[2] 
	double c3 = refcube_const(rd); // ra is rd is side
	double c4 = refcube_const(*pd); // ra is *pd is side
	double c5 = refcube_const(edge); // ra is temporary variable
	double c6 = refcube_const(7.0); // ra is temporary variable(not lvalue)
	double c7 = refcube_const(side + 10.0); // ra is temporary variable
	//double c8 = refcube_const("string"); // ra is temporary variable
	long a = 3, b = 5;
	//swapr(a, b);//temporary doesn't work in no const ref
	return 0;
}
double cube(double a)
{
	a *= a * a;
	return a;
}
double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
double refcube_const(const double &ra)
{
	return ra * ra * ra;
}

void swapr(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
