/*20210111 21:26,zyj,GuangDong*/
#include <iostream>
#include <math.h>
int main ()
{
	using namespace std;
	double && rref = std::sqrt(36.00); // not allowed for double &
	double j = 15.0;
	double && jref = 2.0* j + 18.5; // not allowed for double &
	std::cout << rref << '\n'; // display 6.0
	std::cout << jref << '\n'; // display 48.5;
}
