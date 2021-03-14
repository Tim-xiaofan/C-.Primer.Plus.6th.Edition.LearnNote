/* 20210314 13:32, zyj, GuangDong*/
// format_defaut.cpp -- defaut format of cout
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	//int i = 125;
	//int i1 = 0xffffffff;
	//unsigned int ui = 0xffffffff;
	//float f = 3.1415926;
	//float f1 = 2.50000000;
	//float f2 = -3.1415926;
	//cout << "int : " << i << endl;
	//cout << "int : " << i1 << endl;
	//cout << "unsigned int : " << ui << endl;
	//cout << "float : " << f << endl;
	//cout << "float : " << f1 << endl;
	//cout << "float : " << f2 << endl;

	cout << "12345678901234567890\n";
	char ch = 'K';
	int t = 273;
	cout << ch << ":\n";
	cout << t << ":\n";
	cout << -t <<":\n";

	double f1 = 1.200;
	cout << f1 << ":\n";
	cout << (f1 + 1.0 / 9.0) << ":\n";

	double f2 = 1.67E2;
	cout << f2 << ":\n";
	f2 += 1.0 / 9.0;
	cout << f2 << ":\n";
	cout << (f2 * 1.0e4) << ":\n";

	double f3 = 2.3e-4;
	cout << f3 << ":\n";
	cout << f3 / 10 << ":\n";

	return 0;
}
