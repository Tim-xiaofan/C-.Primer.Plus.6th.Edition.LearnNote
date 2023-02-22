#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	cout << "What is your first name? ";
	char first[20];
	cin.getline(first, sizeof first);
	
	cout << "What is your last name? ";
	char last[20];
	cin.getline(last, sizeof last);

	cout << "What letter grade do you deserve? ";
	char grade;
	cin.get(grade);
	cin.get();

	cout << "What is your age? ";
	int age;
	cin >> age;

	cout << "Name: " << first << " " << last << endl;
	grade += 1;
	cout << "Grade: " << grade << endl;
	cout << "Age: " << age << endl;
	
	return 0;
}
