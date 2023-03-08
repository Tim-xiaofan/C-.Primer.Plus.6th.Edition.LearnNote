// 20230308 zyj, GaungDong, 
#include <iostream>
#include "worker.h"

using std::endl;
using std::cout;

int main(void)
{
	singing_waiter ed;
	worker* pw0 = &ed; // ambiguous
	cout << "pw0 = " << pw0 << endl;

	worker* pw1 = reinterpret_cast<singer*>(&ed);
	cout << "pw1 = " << pw1 << endl;
	worker* pw2 = reinterpret_cast<waiter*>(&ed);
	cout << "pw2 = " << pw2 << endl;
	cout << "pw2 == pw1: " << std::boolalpha
		<< (pw1 == pw2) << endl;

	singer s;
	waiter w;
	worker* ws[] = {pw1, &s, &w}; 
	for(int i = 0; i < 3; ++i)
	{
		cout << endl;
		ws[i]->show();
		cout << endl;
	}
	return 0;
}
