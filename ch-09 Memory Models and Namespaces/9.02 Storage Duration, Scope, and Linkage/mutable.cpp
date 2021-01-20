/*20210120 21:54,zyj,GuangDong*/
// mutable.cpp -- mutable usage
#include <iostream>
#include <cstring>
struct data
{
	char name[30];
	mutable int accesses;
};

int main()
{
	const data veep = {"Claybourne Clodde", 0};
	//strcpy(veep.name, "Joye Joux"); // not allowed
	veep.accesses++; // allowed
}
