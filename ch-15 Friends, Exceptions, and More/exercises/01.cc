//202303013 09:34, zyj, GuangDong
#include <iostream>
#include "tv.h"

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	Tv tv;
	Remote r;
	r.show_control();
	cout << "after tv set_remote_control" << endl;
	tv.set_remote_control(r);
	r.show_control();
	cout << "after tv on and tv set_remote_control" << endl;
	tv.onoff();
	tv.set_remote_control(r);
	r.show_control();
	return 0;
}
