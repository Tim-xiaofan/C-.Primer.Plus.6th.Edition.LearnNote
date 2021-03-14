/* 20210314 16:01, zyj, GuangDong*/
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	cout.setf(ios_base::showpoint); // show trailing decimal point
	cout << "5.0623 : " << 5.0623 << endl;
	cout.unsetf(ios_base::showpoint); // don't show trailing decimal point
	cout << "5.0623 : " << 5.0623 << endl;
	cout.setf(ios_base::boolalpha); // display true, false
	cout << "true : " << true << endl;
	cout.unsetf(ios_base::boolalpha); // display 1, 0
	cout << "true : " << true << endl;
}
