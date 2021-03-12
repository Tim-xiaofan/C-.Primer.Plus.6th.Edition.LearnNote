/* 20210312 21:31, zyj, GuangDong*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
	vector<string> words;
	cout << "Enter words (enter quit to quit):\n";
	string input;

	ifstream fin;
	fin.open("input.txt");
	if(!fin.is_open())
	{
		cout << "cannot open file \"input.txt\"" << endl;
		exit(-1);
	}
	while (fin >> input && input != "quit")
	  words.push_back(input);

	cout << "You entered the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	// place words in set, converting to lowercase
	/** vector to set*/
	/** #1: range constructor, ok*/
	set<string> wordset(words.begin(), words.end());

	/** #2: transform, ok*/
	//transform(words.begin(), words.end(),
	//			insert_iterator<set<string> > (wordset, wordset.begin()),
	//			ToLower);

	/** #3: copy, ok*/
	copy(words.begin(), words.end(),
				insert_iterator<set<string> >(wordset, wordset.begin()));

	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;


	// place word and frequency in map
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
	  wordmap[*si] = count(words.begin(), words.end(), *si);

	// display map contents
	cout << "\nWord frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
	  cout << *si << ": " << wordmap[*si] << endl;

	cout << "wordmap[\"test\"] :" << wordmap["test"] << endl;
	return 0;
}

string & ToLower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string & s)
{
	cout << s << " ";
}
