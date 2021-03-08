/* 20210308 22:31, zyj, GuangDong*/
// insert_iterator.cpp -- usage of insert iterator
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>
#include <cstdint>

using namespace std;

const string months[12]=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Aguest",
	"September",
	"October",
	"November",
	"December"
};


void output(const std::string & s) {std::cout << s << " ";}
int main()
{
	using namespace std;
	string s1[4] = {"fine", "fish", "fashion", "fate"};
	string s2[2] = {"busy", "bats"};
	string s3[2] = {"silly", "singers"};
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;
	// construct anonymous back_insert_iterator object
	copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	// construct anonymous insert_iterator object
	copy(s3, s3 + 2, insert_iterator<vector<string> >(words,
					words.begin() + 1));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	return 0;
}
