/*20210110 15:07,zyj,GuangDong*/
// inline.cpp -- using an inline function
#include <iostream>
// an inline function definition
inline double square(double x) { return x * x; }
#define SQUARE(X) X*X
#define SQUARE1(X) (X)*(X)
int main()
{
	using namespace std;
	cout << "square(5.0) = " << square(5.0) << endl;
	cout << "SQUARE(5.0) = " << SQUARE(5.0) << endl;/*smple repalce:"5.0 *5.0"*/
	cout << "square(5.0 + 4.0) = " << square(5.0 + 4.0) << endl;
	cout << "SQUARE(5.0 + 4.0) = " << SQUARE(5.0 + 4.0) << endl;/* simle repalce: "5.0 +4.0 * 5.0 + 4.0" */
	double a = 4.0, b = 4.0;
	cout << "a++ square is " << square(a++) << ", after a = " << a << endl;
	cout << "b++ SQUARE1 is " << SQUARE1(b++) << ", after b = " << b << endl;/*macros not pass by value*/
	return 0;
}
