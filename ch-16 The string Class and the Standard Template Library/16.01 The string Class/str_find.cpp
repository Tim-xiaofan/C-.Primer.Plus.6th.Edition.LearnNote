/* 20210303 21:21, zyj, GuangDong*/
// str_find.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define FILENAME "text.txt"
int main()
{
	using namespace std;
	ifstream fin;
	fin.open(FILENAME);
	if(!fin.is_open())
	{
		cout << "cannot open " << FILENAME << endl;
		exit(-1);
	}
	string text;
	getline(fin, text, '#');
	
	int i, len = text.length();
	for(i = 0; i < len; i++)
	  cout << "<"<< i <<">" <<text[i];

	/** size_type find(const string &str, *	size_type pos = 0) const*/
	string substr("find");
	cout << "\"find\" at index = " << text.find(substr, 50)
		<< " if start index 50\n";

	/** size_type find(const char * s,size_type pos = 0) const*/
	cout << "\"string\" at index = " << text.find("string", 50) 
		<< " if start index 50\n";

	/** size_type find(const char * s,size_type pos = 0, size_type n)*/
	// same as text.find("string", 50)
	cout << "\"string\" at index = " << text.find("stringbahsasa", 50, 6) 
		<< " if start index 50\n";

	/** size_type find(char ch, size_type pos = 0) const */
	cout << "\"s\" at index = " << text.find('s', 50) 
		<< " if start index 50\n";

	cout << "\"string\" first at index = " << text.find("string") << endl; 
}
