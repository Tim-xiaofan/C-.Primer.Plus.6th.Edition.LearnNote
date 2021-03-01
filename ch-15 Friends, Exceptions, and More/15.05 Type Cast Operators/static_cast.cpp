/* 20210301 21:35, zyj, GuangDong*/
// static_cast.cpp -- using const_cast<>
#include <iostream>
using std::cout;
using std::endl;

class High
{
	char h;
};

class Low:public High
{
	int l;
};

class Pond
{
	char * str;
};

int main()
{
	High bar;
	Low blow;
	High * pb = static_cast<High *> (&blow); // valid upcast
	Low * pl = static_cast<Low *> (&bar); // valid downcast
	Pond * pmer = static_cast<Pond *> (&blow); // invalid, Pond unrelated
}
