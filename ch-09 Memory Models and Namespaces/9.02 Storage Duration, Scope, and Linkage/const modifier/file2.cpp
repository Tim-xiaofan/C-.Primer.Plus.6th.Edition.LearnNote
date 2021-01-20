/*20210120 22:10,zyj,GuangDong*/
// file2.cpp
#include <iostream>
#include "common.h"

int f(void)
{
	using namespace std;
	cout <<"file2.cpp:" <<endl; 
	cout << fingers << "," <<  &fingers << endl;
	cout << warning << "," << &warning << endl;
	return 0;
}
