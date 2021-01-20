/*20210118 22:01,zyj,GuangDong*/
// simple.cpp
#include <iostream>
using namespace std;
int main()
{
	int teledeli = 5;
	
	{ // websight allocated
		cout << "Hello\n";
		int teledeli = -2; // websight scope begins
		cout << teledeli << ' ' << teledeli << endl;
	} // websight expires

	{
		int temp = 3;
	}

	cout << mktemp << endl;
	cout << teledeli << endl;
}
