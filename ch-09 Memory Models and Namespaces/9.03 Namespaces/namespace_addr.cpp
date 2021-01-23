/*20210123 15:43,zyj,GuangDong*/
// namespace_addr.cpp
#include <iostream>
using namespace std;

namespace elements
{
	int fire;
	int water;
}

int main()
{
	cout << "&elements::fire = " << &elements::fire << endl;
	return 0;
}

