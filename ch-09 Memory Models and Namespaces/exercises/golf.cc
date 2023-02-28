#include <iostream>
#include <cstring>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;

void setgolf(golf & g, const char * name, int hc)
{
	strncpy(g.fullname, name, Len - 1);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	cout << "Enter name: ";
	cin.getline(g.fullname, Len - 1);
	if(strlen(g.fullname))
	{
		cout << "Enter handicap: ";
		cin >> g.handicap;
		cin.get();
		return 1;
	}
	
	return  0;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << g.fullname << ", "
		<< g.handicap << endl;
}
