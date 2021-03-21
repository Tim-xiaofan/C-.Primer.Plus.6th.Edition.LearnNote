/* 20210320 20:30, zyj, GuangDong*/
// rvalue_reference.cpp
#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	int n;
	int * pt = new int;
	const int b = 101; // can't assign to b, but &b is valid
	int & rn = n; // n identifies datum at address &n
	int & rt = *pt; // *pt identifies datum at address pt
	const int & rb = b; // b identifies const datum at address &b

	int x = 10;
	int y = 23;
	int && r1 = 13;
	int && r2 = x + y;
	double && r3 = std::sqrt(2.0);
}
