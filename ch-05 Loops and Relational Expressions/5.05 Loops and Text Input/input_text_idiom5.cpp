/*20201227 16:01,zyj,GuangDong*/
// input_text_idiom5.cpp -- one idioms
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	ch = cin.get();
	while (ch != EOF) // test for EOF
	{
		cout.put(ch); // echo character
		++count;
		ch = cin.get();
	}
	cout << endl << count << " characters read\n";
	return 0;
}
