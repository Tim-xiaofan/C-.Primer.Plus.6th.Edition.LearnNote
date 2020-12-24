/*20201224 21:33,zyj,GuangDong*/
//rane_based_for.cpp --usage
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
	cout << "origin price:" << endl;
	for (double x : prices)
	  cout << x << std::endl;
	cout << "20% off sale:" << endl;
	for (double &x : prices)
	  x = x * 0.80;
	for (double x : prices)
	  cout << x << std::endl;
	cout << "list initialization:" << endl;
	for (int x : {3, 5, 2, 8, 6})
	  cout << x << " ";
	cout << '\n';
	return 0;
}
