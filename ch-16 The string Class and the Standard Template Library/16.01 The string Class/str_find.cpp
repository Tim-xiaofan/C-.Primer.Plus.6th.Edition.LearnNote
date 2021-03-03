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
	/** size_type find(const string &str, 
	  size_type pos = 0) const*/
	ifstream fin;
	fin.open(FILENAME);
	if(!fin.is_open())
	{
		cout << "cannot open " << FILENAME << endl;
		exit(-1);
	}
	string text;
	getline(fin, text, '#');
	cout << text << endl;
}
