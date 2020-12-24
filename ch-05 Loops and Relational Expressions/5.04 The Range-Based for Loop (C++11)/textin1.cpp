/*20201224 21:58,zyj,GuangDong*/
// textin1.cpp -- reading chars with a while loop
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	char ch;
	int count = 0; // use basic input
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch; // get a character
	while (ch != '#') // test the character
	{
		cout << "get:" << ch << endl; // echo the character
		++count; // count the character
		cin >> ch; // get the next character
	}
	cout << endl << count << " characters read, don't inlude space,tab,newline\n";
	return 0;
}
