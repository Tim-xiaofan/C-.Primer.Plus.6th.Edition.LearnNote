#include <cstring>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	char fisrt[60];
	char last[20];
	cout << "Enter your first name: ";
	cin.getline(fisrt, 20); // reads through newline
	cout << "Enter your last name: ";
	cin.getline(last, 20);

	strcat(fisrt, ", ");
	cout << strcat(fisrt, last) << endl;
	return 0;
}
