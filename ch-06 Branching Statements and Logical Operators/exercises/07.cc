#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void)
{
	string word;
	int vowels = 0;
	int consonants = 0;
	int others = 0;
	cout << "Enter words (q to quit):\n";
	while((cin >> word) && (word != "q"))
	{
		if(isalpha(word[0]))
		{
			if(word[0] == 'a' ||
						word[0] == 'e' ||
						word[0] == 'i' ||
						word[0] == 'o' ||
						word[0] == 'u')
			{
				++vowels;
			}
			else
			{
				++consonants;
			}
		}
		else
		{
			++others;
		}
	}
	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;
	return 0;
}
