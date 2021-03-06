/* 20210306 15:14, zyj, GuangDong*/
// uniqueptr_poor.cpp -- uniqueptr_poor a poor choice
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
	unique_ptr<string> films[5] =
	{
		unique_ptr<string> (new string("Fowl Balls")),
		unique_ptr<string> (new string("Duck Walks")),
		unique_ptr<string> (new string("Chicken Runs")),
		unique_ptr<string> (new string("Turkey Errors")),
		unique_ptr<string> (new string("Goose Eggs"))
	};
	unique_ptr<string> pwin;
	unique_ptr<int> pi (new int(15));
	cout << "*pi = " << *pi << endl;
	//pwin = films[2]; // just forbit dangerous assignment
	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	  cout << *films[i] << endl;
	//cout << "The winner is " << *pwin << "!\n";
	//cin.get();

	unique_ptr<string> ps;
	ps = demo("Uniquely special");
	return 0;
}
