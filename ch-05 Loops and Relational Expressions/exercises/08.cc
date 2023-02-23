#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{	
	char word[128];
	int count = 0;

	cout << "Enter words (to stop, type the word done):\n";
	cin >> word;
	while(strcmp(word, "done"))
	{
		++count;
		cin >> word;
	}
	cout << "You entered a total of "<< count <<" words.\n";
	return 0;
}
