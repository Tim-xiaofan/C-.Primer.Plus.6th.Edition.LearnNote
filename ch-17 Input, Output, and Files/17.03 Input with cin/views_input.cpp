/* 20210314 17:13, zyj, GuangDong*/
// views_input.cpp -- How cin >> Views Input
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char philosophy[20];
	int distance;
	char initial;
	cout << "enter a string, integer and char :";
	cin >> philosophy >> distance >> initial;
	cout << setw(13) << left  <<"philosophy :" 
		<< setw(13) << left << philosophy << endl;
	cout << setw(13) << left  <<"distance :" 
		<< setw(13) << left << distance << endl;
	cout << setw(13) << left  <<"initial :"
		<< setw(13) << left << initial << endl;


	while(cin.get() != '\n');
	cout << "enter an integer : ";
	int elevation;
	cin >> elevation;
	cout << "elevation : " << elevation << endl;
}
