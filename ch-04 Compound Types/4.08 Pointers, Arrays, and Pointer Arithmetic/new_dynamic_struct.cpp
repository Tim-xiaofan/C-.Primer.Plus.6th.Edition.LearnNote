/*20201222 22:36,zyj,GuangDong*/
// newstrct.cpp -- using new with a structure
#include <iostream>
struct inflatable // structure definition
{
	char name[20];
	float volume;
	double price;
};
int main(int argc, char *argv[])
{
	using namespace std;
	inflatable * ps = new inflatable; // allot memory for structure like build-in type
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20); // method 1 for member access
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume; // method 2 for member access
	cout << "Enter price: $";
	cin >> ps->price;// method 3 for member access
	cout << "Name: " << (*ps).name << endl; // method 2
	cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
	cout << "Price: $" << ps->price << endl; // method 1
	delete ps; // free memory used by structure
	ps = NULL;
	return 0;
}
