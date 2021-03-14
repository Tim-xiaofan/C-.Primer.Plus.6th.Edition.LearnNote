/* 20210314 20:40, zyj, GuangDong*/
//  string_input.cpp -- get single_character input
#include <iostream>
#include <iomanip>
#define READ_MAX 50

int main()
{
	using namespace std;

	char input[READ_MAX], ch;
	int ct = 0;

	while(cin.get(input, READ_MAX)) /** failed if empty line or EOF*/
	{
		cout << "#" << ct++ << " "
			<< input << endl;
		/** clear newline characte*/
		cin.get(ch);
	}

	//while(cin.get() != '\n'); //don't work
	cin.ignore();
	cin.clear();
    clearerr(stdin); /** reset the stream*/

	/** discard tow lines*/
	cin.ignore(255, '\n').ignore(255, '\n');
	ct = 0;
	while(cin.getline(input, READ_MAX)) /** failed if EOF*/
	{
		cout << "#" << ct++ << " "
			<< input << endl;
	}
}
