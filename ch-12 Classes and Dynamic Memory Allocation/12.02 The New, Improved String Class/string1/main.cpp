/** 20210201 21:53,zyj,GuangDong*/
// compile with string.cpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "string.h"

int main()
{
	using std::endl;
	{
		String name;
		char temp[40];
		cin.getline(temp, 40);
		name = temp; // use constructor to convert type
		cout << "name = " << name << endl;
		cout << "Enter an integer:\n";
		int i;
		cin >> i;
		name = i;
		cin.get();
		cout << "name = " << name << endl;
		
		String text;
		cin >> text;
		cout << "text = " << text << endl;
		text = 'A';
		cout << "text = " << text << endl;

		text = name = 125;
		cout << "text = " << text << endl;
		cout << "name = " << text << endl;
	}
	cout << "End of main()\n";
	return 0;
}

