/* 20210313 22:18, zyj, GuangDong*/
// insertion_operator.cpp -- overload << operator
#include <iostream>

using namespace std;

int main()
{
	int clients = 1;
	cout << clients << endl;
	cout << clients << 2 << endl;
	cout << (clients << 2) << endl;
	cout.operator<<(clients) << endl;
	cout.operator<<(clients) << 2 << endl;
	cout.operator<<(clients << 2) << endl;

	/** output pointer*/
	char name[20] = "Dudly Diddlemore";
	char *pn = "Violet D'Amore";
	cout << "Hello!" << endl;
	cout << name << endl;
	cout << pn << endl;

	/** address*/
	int eggs = 12;
	char *amount = "dozen";
	cout << &eggs << endl; // prints address of eggs variable
	cout << amount << endl; // prints the string "dozen"
	cout << (void *) amount << endl; // prints the address of the "dozen" string
}
