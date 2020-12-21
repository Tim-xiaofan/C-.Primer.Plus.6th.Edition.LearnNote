/*20201221 21:06,zyj,GuangDong*/
// delete_usage.cpp
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	int * ps = new int; // ok
	delete ps; // ok
	delete ps; // not ok now
	int jugs = 5; // ok
	int * pi = &jugs; // ok
	delete pi; // not allowed, memory not allocated by new
	return 0;
}
