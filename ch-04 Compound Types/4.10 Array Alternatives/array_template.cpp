/*20201223 22:06,zyj,GuangDong*/
// array_template.cpp
#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
	using namespace std;
	array<int, 5> ai; // create array object of 5 ints
	array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
	cout << "sizeof(ai)" << sizeof(ai) << endl;
	cout << "sizeof(ad)" << sizeof(ad) << endl;
	return 0;
}
//sizeof(ai)20
//sizeof(ad)32
