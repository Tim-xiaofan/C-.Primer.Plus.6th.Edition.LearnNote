/*20201224 08:52,zyj,GuangDong*/
// input_text_idiom2.cpp -- one idioms
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	while (!cin.fail()) // test for EOF
	{
		cin.get(ch); // attempt to read another char
		cout << ch; // echo character
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
