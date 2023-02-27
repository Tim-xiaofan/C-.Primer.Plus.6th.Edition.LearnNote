#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

static string& toupper(string& str)
{
	std::for_each(str.begin(),
				str.end(),
				[](char& ch)
				{ if(islower(ch)) {ch = ::toupper(ch);}});
	return str;
}

int main(void)
{
	string str;
	cout << "Enter string: ";
	while(getline(std::cin, str) && str != "q")
	{
		cout << toupper(str) << endl;
		cout << "Next string: ";
	}
	return 0;
}
