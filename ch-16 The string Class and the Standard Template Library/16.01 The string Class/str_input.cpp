/* 20210302 21:53, zyj, GuangDong*/
// str_input.cpp -- introducing the string class .Page 957
#include <iostream>
#include <string>
// using string input
int main()
{
	using namespace std;
	/** C-style string*/
	char info[100];
	cout << "-------C-style-------\n";
	cout << "cin:";
	cin >> info; // read a word
	cout << "info = " << info << endl;
	while(cin.get() != '\n');

	cout << "cin.getline:";
	cin.getline(info, 100); // read a line, discard \n
	cout << "info = " << info << endl;

	cout << "cin.get:";
	cin.get(info, 100); // read a line, leave \n in queue
	cout << "info = " << info << endl;

	/** no opportunity to enter*/
	cout << "cin.getline2:";
	cin.getline(info, 100); // read a line, discard \n
	cout << "info = " << info << endl;

	/** delimit input */
	cout << "cin.getline with ':' as delimit:";
	cin.getline(info, 100,':'); // read up to :, discard :
	cout << "info = " << info << endl;

	/**C++ class string */
	cout << "-------C++ string-------\n";
	string stuff;
	cout << "cin:";
	cin >> stuff; // read a word
	cout << "stuff = " << stuff << endl;
	while(cin.get() != '\n');

	cout << "getline(cin, string):";
	getline(cin, stuff); // read a line, discard \n
	cout << "stuff = " << stuff << endl;
	
	/** delimit input */
	cout << "getline with ':' as delimit:";
	getline(cin, stuff,':'); // read up to :, discard :
	cout << "stuff = " << info << endl;
}
