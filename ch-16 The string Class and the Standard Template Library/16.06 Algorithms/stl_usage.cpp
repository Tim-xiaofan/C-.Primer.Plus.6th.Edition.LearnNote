/* 20210312 12:42, zyj, GuangDong*/
//stl_usage.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cctype>

using namespace std;

char toLower(char ch) { return tolower(ch); }

string & mtolower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

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

	cout << "\nwords:";
	copy(words.begin(), words.end(), out);
	cout << endl;
	
	cout << "\nif ignore case, words:";
	/**vector can work well */
	transform(words.begin(), words.end(), words.begin(), mtolower);
	copy(words.begin(), words.end(), out);
	cout << endl;
	
	cout << "\nwordset:";
	copy(wordset.begin(), wordset.end(), out);
	cout << endl;

	/** set cannot work : just compile failed
	 *	reson:The value of an element in a set 
	 *	may not be changed directly
	 */
	//cout << "\nif ignore case, wordset:";
	//transform(wordset.begin(), wordset.begin(), 
	//			wordset.begin(), mtolower);
	//copy(wordset.begin(), wordset.end(), out);
	//cout << endl;

	set<string> wordset1;
	transform(words.begin(), words.end(),
				insert_iterator<set<string> >(wordset1, wordset1.begin()), mtolower);
	cout << "\nwordset1:";
	copy(wordset1.begin(), wordset1.end(), out);
	cout << endl;
}
