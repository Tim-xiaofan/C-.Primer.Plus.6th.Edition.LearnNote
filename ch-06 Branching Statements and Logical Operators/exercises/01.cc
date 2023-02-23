#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	char ch;
	cin.get(ch);
	while(ch != '@')
	{
		if(isdigit(ch))
		{
			cin.get(ch);
		}
		else
		{
			if(islower(ch))
			{
				ch = toupper(ch);
			}
			else if(isupper(ch))
			{
				ch = tolower(ch);
			}
			cout << ch;
			cin.get(ch);
		}
	}
	return 0;
}
