/*20201224 08:50,zyj,GuangDong*/
// vector_cmp_array.cpp --  similarities and differences between arrays,vector objects
#include <iostream>
#include <vector> // STL C++98
#include <array> // C++11
int main(int argc, char *argv[])
{
	using namespace std;
	// C, original C++
	double a1[4] = {1.2, 2.4, 3.6, 4.8};
	// C++98 STL
	vector<double> a2(4); // create vector with 4 elements
	// no simple way to initialize in C98
	a2[0] = 1.0/3.0;
	a2[1] = 1.0/5.0;
	a2[2] = 1.0/7.0;
	a2[3] = 1.0/9.0;
	// C++11 -- create and initialize array object
	array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
	array<double, 4> a4;
	a4 = a3; // valid for array objects of same size
	// use array notation
	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	//int i;
	//for(i = 0; i < 4; i++)
	//{
	//	cout << "a1["<<i<<"]: " << a1[i] << " at " << &a1[i] << endl;
	//	cout << "a2["<<i<<"]: " << a2[i] << " at " << &a2[i] << endl;
	//	cout << "a3["<<i<<"]: " << a3[i] << " at " << &a3[i] << endl;
	//	cout << "a4["<<i<<"]: " << a4[i] << " at " << &a4[i] << endl;
	//}
	// misdeed
	cout << endl;
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] <<" at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	a2.at(56) = 56;
	cout << "a2[56]:" << a4[56] << endl;
	return 0;
}
//a1[2]: 3.6 at 0xffffcbb7e048
//a2[2]: 0.142857 at 0xaaaae299de80
//a3[2]: 1.62 at 0xffffcbb7e068
//a4[2]: 1.62 at 0xffffcbb7e088
//a1[-2]: 20.2 at 0xffffcbb7e028
//a3[2]: 1.62 at 0xffffcbb7e068
//a4[2]: 1.62 at 0xffffcbb7e088
