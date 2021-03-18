/* 20210318 21:44, zyj, GuangDong*/
// newtype.cpp -- C++ 11 newtypes
#include <iostream>

int main()
{
	using namespace std;
	cout << "sizeof(long): " << 
		sizeof (long) << endl;
	cout << "sizeof(long long): " << 
		sizeof (long long) << endl;
	cout << "sizeof(char16_t): " << 
		sizeof (char16_t) << endl;
	cout << "sizeof(char32_t): " << 
		sizeof (char32_t) << endl;

	//char16_t ch16;
	//char32_t ch32;
	//cin >> ch16;
	//cout << "ch16 : " << ch16 << endl;
	//cin >> ch32;
	//cout << "ch32 : " << ch32 << endl;
}
