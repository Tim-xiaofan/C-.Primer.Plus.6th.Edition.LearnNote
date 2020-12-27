/*20201224 08:52,zyj,GuangDong*/
// input_text_idiom1.cpp -- one idioms
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch); // attempt to read a char
	while (cin.fail() == false) // test for EOF
	{
		cout << ch; // echo character
		++count;
		cin.get(ch); // attempt to read another char
	}
	cout << endl << count << " characters read\n";
	return 0;
}
