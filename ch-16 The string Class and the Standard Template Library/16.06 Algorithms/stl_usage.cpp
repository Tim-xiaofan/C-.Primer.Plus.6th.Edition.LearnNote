/* 20210312 12:42, zyj, GuangDong*/
//stl_usage.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	vector<string> words;
	set<string> wordset;
	string input;
	ostream_iterator<string, char> out(cout, " ");
	ifstream fin;
	fin.open("input.txt");

	while((fin >> input) && (input != "quit"))
	{
		words.push_back(input);
		wordset.insert(input);
	}

	cout << "words:";
	copy(words.begin(), words.end(), out);
	cout << endl;
	
	cout << "wordset:";
	copy(wordset.begin(), wordset.end(), out);
	cout << endl;
}
