/** 20210413 10:31, zyj, GuangDong*/
// rlref.cpp -- lvalue reference and rvalue reference
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	/** traditional lvalue reference*/
	int a = 1;
	int & ra = a; 
	int a1 = ra;
	ra = 2;
	cout << a << "," << ra << "," << a1<< endl;
	//int & ra1;/** error : declared as reference but not initialized*/
	//int & var = 10 ;/** error cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’*/
	const int & var = 10;/** ok*/
	//var = 10;/** error : assignment of read-only reference ‘var’*/

	/** C++11 rvalue reference */
	int && rr = 10; /** OK*/
	cout << "rr = " << rr<< endl;
	rr = 11;
	cout << "rr = " << rr<< endl;
	return 0;
}
