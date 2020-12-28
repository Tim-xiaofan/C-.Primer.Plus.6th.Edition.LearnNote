/*20201227 17:26,zyj,GuangDong*/
// cctypes.cpp -- using the ctype.h library
#include <iostream>
#include <cctype> // prototypes for character functions
int main(int argc, char *argv[])
{
	using namespace std;
	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	cin.get(ch); // get first character
	while (!cin.fail()) // test for EOF
	{
		if(isalpha(ch)) // is it an alphabetic character?
		  chars++;
		else if(isspace(ch)) // is it a whitespace character?
		  whitespace++;
		else if(isdigit(ch)) // is it a digit?
		  digits++;
		else if(ispunct(ch)) // is it punctuation?
		  punct++;
		else
		  others++;
		cin.get(ch); // get next character
	}
	cout << chars << " letters, "
		<< whitespace << " whitespace, "
		<< digits << " digits, "
		<< punct << " punctuations, "
		<< others << " others.\n";
	return 0;
}
