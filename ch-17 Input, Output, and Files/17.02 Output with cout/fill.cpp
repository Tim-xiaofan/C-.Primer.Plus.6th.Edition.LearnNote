/* 20210314 14:41, zyj, GuangDong*/
// fill.cpp --  fills unused parts of a field
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << '#';
	cout.width(12);
	cout << 12 << "#" << 24 << "#\n";

	/**  C++ never truncates data*/
	cout.width(1);
	cout << 123456 << endl;

	int w = cout.width(30);
	cout << "default field width = " << w << ":\n";

	cout.width(5);
	cout << "N" <<':';
	cout.width(8);
	cout << "N * N" << ":\n";
	cout.fill('0');

	for (long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i <<':';
		cout.width(8);
		cout << i * i << ":\n";
	}

	cout.fill(' ');
	cout.width(5);
	cout << std::left << "N" <<':';
	cout.width(8);
	cout << std::left << "N * N" << ":\n";

	for (long i = 1; i <= 100; i *= 10)
	{
		//cout.width(5);
		cout << std::setw(5) << std::left << i <<':';
		//cout.width(8);
		cout << std::setw(5) << std::left << i * i << ":\n";
	}

	return 0;
}
