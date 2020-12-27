/*20201224 09:09,zyj,GuangDong*/
// input_text_idiom4.cpp -- one idioms
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	while (cin.get(ch)) // test for EOF
	{
		cout << ch; // echo character
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
