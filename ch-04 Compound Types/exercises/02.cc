#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void)
{
	string name;
	string dessert;
	cout << "Enter your name:\n";
	getline(cin, name); // reads through newline
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
