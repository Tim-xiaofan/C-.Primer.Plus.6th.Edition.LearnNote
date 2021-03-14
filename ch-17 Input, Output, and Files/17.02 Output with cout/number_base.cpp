/* 20210314 14:10, zyj, GuangDong*/
// number_base.cpp -- change number base to display
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	hex(cout);
	cout << "hex(15) = " << 15 << endl;
	cout << "hex(255) = " << 255 << endl;
	oct(cout);
	cout << "oct(15) = " << 15 << endl;
	cout << "oct(255) = " << 255 << endl;
}
