/* 20210306 15:52, zyj, GuangDong*/
// sharedptr_poor.cpp -- sharedptr_poor a poor choice
#include <iostream>
#include <string>
#include <memory>
using namespace std;

/** not dangerous to assignment*/
shared_ptr<string> demo(const char * s)
{
	shared_ptr<string> temp(new string(s));
	return temp;
}

int main()
{
	shared_ptr<string> films[5] =
	{
		shared_ptr<string> (new string("Fowl Balls")),
		shared_ptr<string> (new string("Duck Walks")),
		shared_ptr<string> (new string("Chicken Runs")),
		shared_ptr<string> (new string("Turkey Errors")),
		shared_ptr<string> (new string("Goose Eggs"))
	};
	shared_ptr<string> pwin;
	shared_ptr<int> pi (new int(15));
	cout << "*pi = " << *pi << endl;
	pwin = films[2]; /** just increase count*/
	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	  cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	//cin.get();

	shared_ptr<string> ps;
	ps = demo("Uniquely special");
	return 0;
}
