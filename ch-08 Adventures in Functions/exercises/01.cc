#include <iostream>

using std::cout;
using std::endl;

static void print_string(const char* str, int flags = 0)
{
	static int called_ct = 0;
	++called_ct;
	if(flags)
	{
		for(int i = 0; i < called_ct; ++i)
		{
			cout << str << endl;
		}
	}
	else
	{
		cout << str << endl;
	}
}

int main(void)
{
	print_string("str");
	print_string("str", 1);
	return 0;
}
