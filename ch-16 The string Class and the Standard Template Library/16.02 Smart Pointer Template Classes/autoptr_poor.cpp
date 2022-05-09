/* 20210306 15:14, zyj, GuangDong*/
// autoptr_poor.cpp -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>
int main()
{
	using namespace std;
	auto_ptr<string> films[5] =
	{
		auto_ptr<string> (new string("Fowl Balls")),
		auto_ptr<string> (new string("Duck Walks")),
		auto_ptr<string> (new string("Chicken Runs")),
		auto_ptr<string> (new string("Turkey Errors")),
		auto_ptr<string> (new string("Goose Eggs"))
	};
	auto_ptr<string> pwin;
	auto_ptr<int> pi(new int(15));
	cout << "*pi = " << *pi << endl;
	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	  cout << *films[i] << endl;
	pwin = films[2]; // films[2] loses ownership
	cout << "The winner is " << *pwin << "!\n";
    cout << "Press enter to quit" << endl;
	cin.get();
	return 0;
}
