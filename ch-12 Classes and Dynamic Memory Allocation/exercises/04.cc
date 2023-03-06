//20230306, zyj, GUANGDONG
#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	Stack s1(8);
	Item i = 1;
	while(s1.push(i))
	{
		++i;
	}
	cout << s1 << endl;
	Stack s2 = s1;
	Stack s3(0);
	while(s1.pop(i))
	{
		cout << s1 << endl;
	}
	cout << s2 << endl;
	s3 = s2;
	cout << s3 << endl;
	return 0;
}
