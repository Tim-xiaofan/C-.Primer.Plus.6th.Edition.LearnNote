#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static void
prompt(void)
{
	cout << "Please enter a c, p, t, or g:";
}

int main(void)
{
	char ch;
	prompt();
	while((cin >> ch) && (ch != 'q'))
	{
		switch(ch)
		{
			case 'c':
				cout << "carnivore" << endl;
				break;
			case 'p':
				cout << "panist" << endl;
				break;
			case 't':
				cout << "A maple is a tree." << endl;
				break;
			case 'g':
				cout << "game" << endl;
				break;
			default:
				break;
		}
		prompt();
	}
	return 0;
}
