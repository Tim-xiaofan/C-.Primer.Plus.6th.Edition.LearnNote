/*20210107 20:59,zyj,GuangDong*/
// simple.cpp -- pointer to function
#include <iostream>
using namespace std;

void think(void)
{
	cout << "think" << endl;
}

int main(int argc, char *argv[])
{
	think();
	cout << (void *)think << endl;

	double pam(int); // prototype
	// pf points to a function that takes
	// one int argument and that
	// returns type double
	double (*pf)(int);
	//pf = think;/*not allowed*/
	void (*pthink)(void);
	pthink = think;
	//call think,also
	(*pthink)();
	//not good
	pthink();
	return 0;
}
