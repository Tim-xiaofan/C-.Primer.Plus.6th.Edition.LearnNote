#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

const int ArSize = 101;

int main(void)
{
	array<long double, ArSize> factorials;
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < ArSize; i++)
	  factorials[i] = i * factorials[i-1];
	for (int i = 0; i < ArSize; i++)
	  std::cout << i << "! = " << factorials[i] << std::endl;
	return 0;
}
