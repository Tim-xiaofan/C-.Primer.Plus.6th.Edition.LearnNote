/*20210217 22:07, zyj, GuangDong*/
#include <iostream>
#include <string>
#include "stacktp.h"
#include <time.h>

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
	using std::endl;
	using std::cout;

	/** int */
	Stack<int> stack;
	int i = 0;
	while(stack.push(i)) i++;
	cout << stack;

	/** string*/
	time_t tm;
	int len = 0;
	bool success = true;
	Stack<std::string> s2;
	do
	{
		tm = time(NULL);
		std::string st(ctime(&tm));
		len = st.length();
		st[len -1] = ' ';//rm '\n'
		success = s2.push(st);
		sleep(1);
	}while(success);
	cout << s2;
}
