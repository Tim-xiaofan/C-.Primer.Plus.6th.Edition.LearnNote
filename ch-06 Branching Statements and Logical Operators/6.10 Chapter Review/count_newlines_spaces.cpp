/* 20201228 22:29,zyj,GuangDong*/
// count_newlines_spaces.cpp -- get number of space and newline
#include <iostream>
int main(int arc, char *argv[])
{
	using namespace std;
	// Version 1
	char ch;
	int spaces = 0, newlines = 0;
	while (cin.get(ch)) // quit on eof
	{
		if (ch == ' ')
		  spaces++;
		if (ch == '\n')
		  newlines++;
	}
	cout << "spaces = " << spaces << endl;
	cout << "newlines = " << newlines << endl;
	return 0;
}
