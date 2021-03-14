/* 20210314 13:21, zyj, GuangDong*/
// flush.cpp -- flushing the output buffer
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	cout << "Hello, good-looking! " << flush;
	cout << "Wait just a moment, please." << endl;

	int i;
	for(i = 0; i < 100; i++)
	{
		cout << i;
		flush(cout);
		usleep(100000);
	}
	cout << endl;
}
