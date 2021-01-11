/*20210110 15:39,zyj,GuangDong*/
// firstref.cpp -- defining and using a reference
#include <iostream>
int main()
{
	using namespace std;
	int rats = 101;
	int & rodents = rats; // rodents is a reference
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "after 'rodents++':" << endl;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rats++;
	cout << "after 'rats++':" << endl;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	// some implementations require type casting the following
	// addresses to type unsigned
	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;
	return 0;
}
