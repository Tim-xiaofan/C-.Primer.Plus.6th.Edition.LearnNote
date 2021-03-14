/* 20210314 17:59, zyj, GuangDong*/
//  character_input.cpp -- get single_character input
#include <iostream>

int main()
{
	using namespace std;

	int ct = 0;
	char ch;
	cin.get(ch);
	while (ch != '\n')
	{
		cout << ch;
		ct++;
		cin.get(ch);
	}
	cout << endl << ct << endl;
	
	/** get(void) */
	ct = 0;
	ch = cin.get();
	while (ch != '\n')
	{
		cout << ch;
		ct++;
		ch = cin.get();
	}
	cout << endl << ct << endl;

	int ch1;
	ct = 0;
	while ((ch1 = cin.get()) != EOF)
	{
		cout << (char)ch1;
		ct++;
	}
	cout << endl << ct << endl;

	/** not good*/
	ct = 0;
	cin.ignore(255, '\n');
	cin.clear();
    clearerr(stdin); /** reset the stream*/
	//while (ch != '\n') // FAILS: will skip newline character
	while(cin >> ch)
	{
		cout << ch;
		ct++;
		//cin >> ch;
	}
	cout << endl << ct << endl;
}
