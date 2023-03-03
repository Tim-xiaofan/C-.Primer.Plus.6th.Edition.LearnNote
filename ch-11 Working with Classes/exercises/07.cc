#include <iostream>
#include "complex0.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	complex0 a(3.0, 4.0); // initialize to (3,4i)
	complex0 c;
	cout << "Enter a complex number (q to quit): ";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit): ";
	}
	cout << "Done!\n";
	return 0;
}
