#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void)
{	
	string word;
	int count = 0;

	cout << "Enter words (to stop, type the word done):\n";
	cin >> word;
	while(word != "done")
	{
		++count;
		cin >> word;
	}
	cout << "You entered a total of "<< count <<" words.\n";
	return 0;
}
