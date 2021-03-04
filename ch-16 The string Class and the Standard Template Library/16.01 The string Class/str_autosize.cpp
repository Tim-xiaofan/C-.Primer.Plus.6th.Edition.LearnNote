/* 20210304 21:15, zyj, GuangDong*/
// str_autosize.cpp

#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Sizes:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "Capacities:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Capacity after empty.reserve(50): "
		<< empty.capacity() << endl;
	larger.reserve(10);
	cout << "Capacity after larger.reserve(10): "
		<< larger.capacity() << endl;
	small.reserve(25);
	cout << "Capacity after small.reserve(25): "
		<< small.capacity() << endl;
	return 0;
}
