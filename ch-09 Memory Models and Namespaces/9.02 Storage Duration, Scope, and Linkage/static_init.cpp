/*20210118 22:58,zyj,GuangDong*/
#include <iostream>
using namespace std;

#include <cmath>
int x; // zero-initialization
int y = 5; // constant-expression initialization
long z = 13 * 13; // constant-expression initialization
const double pi = 4.0 * atan(1.0); // dynamic initialization

int main()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << "pi = " << pi << endl;
	return 0;
}
