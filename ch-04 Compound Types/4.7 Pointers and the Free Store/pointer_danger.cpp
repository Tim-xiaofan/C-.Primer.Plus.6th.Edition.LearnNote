/*20201219 22:43,zyj,GuangDong*/
// pointer_danger.cpp -- danger in pointer
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	long * fellow; // create a pointer-to-long
	*fellow = 223323; // place a value in never-never land.error: segment fault
	int * pt;
	pt = 0xB8000000; // type mismatch
	return 0;
}
