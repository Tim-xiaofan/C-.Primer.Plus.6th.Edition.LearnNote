/** 20210216 20:58, zyj, GuangDong*/
#include <iostream>
#include "worker0.h"
const int LIM = 7;
int main()
{
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp("Jerry", 233L, 4);
	Singer s_temp("Tom", 23L, 6);
	SingingWaiter sw1("Spike", 125L, 5, 1);
	SingingWaiter sw2("Muscle", 521L, 5, 1);
	SingingWaiter sw3;
	Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp, &sw1, &sw2, &sw3};
	int i;
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	return 0;
}
