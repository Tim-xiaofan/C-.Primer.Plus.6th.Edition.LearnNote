/*20201224 20:10,zyj,GuangDong*/
// textin2.cpp -- reading chars with a while loop
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	cin.get(ch); // use the cin.get(ch) function
	while (ch != '#') {
		cout << ch;
		++count;
		cin.get(ch); // use it again
	}
	cout << '#' << endl;
	cout << count << " characters read\n";
	return 0;
	return 0;
}
