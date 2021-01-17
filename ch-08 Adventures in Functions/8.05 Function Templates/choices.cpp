/*20210117 13:30,zyj,GuangDong*/
// choices.cpp -- choosing a template
#include <iostream>
template<class T> // or template <typename T>
T lesser(T a, T b) // #1
{
	return a < b ? a : b;
}
int lesser (int a, int b) // #2,abslote value
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}
int main()
{
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;
	cout << lesser(m, n) << endl; // use #2
	cout << lesser(x, y) << endl; // use #1 with double
	cout << lesser<>(m, n) << endl; // donnot use non template,use #1 with int
	cout << lesser<int>(x, y) << endl; // use #1 with int,explicit instantiation
	cout << lesser<short>(x, y) << endl;// use #1
	cout << lesser<long>(m, n) << endl;//use #1
	return 0;
}
