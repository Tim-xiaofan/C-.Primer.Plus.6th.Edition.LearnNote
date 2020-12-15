//instr2.cpp -- reading more than one word with getline
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "Enter your name:\n";
	cin.getline(name, ArSize); // reads through newline, replace newline character with a null character
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
