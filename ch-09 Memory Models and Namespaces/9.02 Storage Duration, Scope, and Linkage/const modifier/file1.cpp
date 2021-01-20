/*20210120 22:10,zyj,GuangDong*/
// file1.cpp
#include <iostream>
#include "common.h"

extern int f(void);

int main()
{
	using namespace std;
	cout <<"file1.cpp:" << endl; 
	cout << fingers << "," <<  &fingers << endl;
	cout << warning << "," << &warning << endl;
	f();
	return 0;
}
