/** 20210130 11:13,zyj,GunagDong*/
#include "vect.h"
#include <iostream>
#define PAI 3.1412526

int main()
{
	using namespace VECTOR;
	using std::cout;
	using std::cin;
	using std::endl;
	Vector v1(1, 1, Vector::RECT);
	cout << "v1 RECT: " << v1 << endl;
	cout << "v1 POL:  " << v1.polar_mode() << endl;
	Vector v2(3, 4, Vector::RECT);
	cout << "v2 RECT: " << v2 << endl;
	cout << "v2 POL:  " << v2.polar_mode() << endl;
	
	cout << "v1 + v2  = " << v1 + v2 << endl;
	cout << "v2 + v1  = " << v2 + v1 << endl;

	cout << "v1 * 0.56 = " << v1 * 0.56 << endl;
	cout << "v2 * 0.56 = " << v2 * 0.56 << endl;
	
	cout << "v1 + v2 * 0.56  = " << v1 + v2 * 0.56 << endl;
	cout << "(v1 + v2) * 0.56  = " << (v1 + v2) * 0.56 << endl;
	
	cout << "|v1| = " << v1.norm() << endl;
	cout << "|v2| = " << v2.norm() << endl;
	cout << "(v1, v2) = " << v1.between_angle(v2) * 180 / PAI<< endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
}
