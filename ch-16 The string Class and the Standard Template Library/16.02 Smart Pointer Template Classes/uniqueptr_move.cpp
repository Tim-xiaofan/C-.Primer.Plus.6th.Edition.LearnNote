/* 20210306 16:00, zyj, GuangDong*/
// uniqueptr_move.cpp -- use std::move to alloen assignment even if it's dangerous
#include <iostream>
#include <string>
#include <memory>
using namespace std;

/** not dangerous to assignment*/
unique_ptr<string> demo(const char * s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

int main()
{
	using namespace std;
	unique_ptr<string> ps1, ps2;
	ps1 = demo("Uniquely special");
	ps2 = move(ps1); // enable assignment and still looses ownership
	//ps1 = demo(" and more");
	cout << *ps2 << *ps1 << endl;
}
