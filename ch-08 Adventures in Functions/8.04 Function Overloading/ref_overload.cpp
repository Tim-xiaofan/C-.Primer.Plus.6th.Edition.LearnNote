/*20210114 21:49,zyj,GuangDong*/
// overloading works with different reference types
#include <iostream>
using namespace std;

void sink(double & r1); // matches modifiable lvalue
void sank(const double & r2); // matches modifiable or const lvalue, rvalue
void sunk(double && r3); // matches rvalue

void stove(double & r1); // matches modifiable lvalue
void stove(const double & r2); // matches const lvalue
void stove(double && r3); // matches rvalue

int main()
{
	double d = 6.6, d1 = 7.7;
	sink(d);
	sank(d + 6.6);
	sunk(d1 * d);

	double x = 55.5;
	const double y = 32.0;
	stove(x); // calls stove(double &)
	stove(y); // calls stove(const double &)
	stove(x+y); // calls stove(double &&)
	return 0;
}


void sink(double & r1)
{// matches modifiable lvalue
	using namespace std;
	cout << "sink :" << r1 << endl;
}
void sank(const double & r2)
{
	using namespace std;
	cout << "sank :" << r2 << endl;
}
void sunk(double && r3) // matches rvalue
{
	using namespace std;
	cout << "sunk :" << r3 << endl;
}

void stove(double & r1)
{
	using namespace std;
	cout << "stove(double & r1) " << r1 << endl;
}
void stove(const double & r2) // matches const lvalue
{
	using namespace std;
	cout << "stove(const double & r2) " << r2 << endl;
}
void stove(double && r3) // matches rvalue
{
	using namespace std;
	cout << "stove(double && r3) " << r3 << endl;
}
