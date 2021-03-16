/* 20210316 08:52, zyj, GuangDong*/
// append.cpp -- appending information to a file
#include <iostream> // not needed for many systems
#include <fstream>
#include <string>
#include <cstdlib>

#define FILE_NAME "guests.txt"

int main()
{
	using namespace std;

	ifstream fin(FILE_NAME, ios::in);
	char ch;
	
	if(!fin.is_open())
	{
		cout << "cannot open file : " << FILE_NAME << endl;
		return 0;
	}

	cout << "original content:\n";
	while(fin.get(ch))cout << ch;
	fin.close();
	fin.clear();

	ofstream fout(FILE_NAME, ios::out | ios::app);
	if(!fout.is_open())
	{
		cout << "cannot open file : %s\n" << FILE_NAME;
		return 0;
	}
	string name;
	cout << "Enter guest names (enter a blank line to quit):\n";
	while(getline(cin, name) && name.size() > 0)
	  fout << name << endl;
	fout.close();
	fout.clear();

	cout << "new content : \n";
	fin.open(FILE_NAME);
	if(!fin.is_open())
	{
		cout << "cannot open file : %s\n" << FILE_NAME;
		return 0;
	}
	while(fin.get(ch))cout << ch;
	fin.close();
	fin.clear();

	return 0;
}
