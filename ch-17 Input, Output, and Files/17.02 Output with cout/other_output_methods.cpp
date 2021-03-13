/* 20210313 22:40, zyj, GuangDong*/
// other_output_methods.cpp -- overload << operator
#include <iostream>

using namespace std;

int main()
{
	/** ostream & put(char);*/
	cout.put('W') << endl; // display the W character
	cout.put('0') << endl;// display the 0  character
	cout.put(49) << endl;// display the character with ASCII code is 49
	cout.put('I').put('t') << endl;

	cout << 'W' << endl;
}
