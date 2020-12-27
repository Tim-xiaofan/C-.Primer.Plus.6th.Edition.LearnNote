/*20201224 09:01,zyj,GuangDong*/
// input_text_idiom3.cpp -- one idioms
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	while (cin) // test for EOF
	{
		cin.get(ch); // attempt to read another char
		cout << ch; // echo character
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
