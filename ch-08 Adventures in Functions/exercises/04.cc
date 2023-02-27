#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

struct stringy 
{
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
	stringy()
		:str(nullptr),
		ct(0)
	{}
	~stringy()
	{ delete str; }
};

static void set(stringy& dst, const char* src)
{
	size_t len = strlen(src);
	dst.str = new char[len + 1];
	strcpy(dst.str, src);
	dst.ct = len;
}

static void show(const stringy& str, int times = 1)
{
	for(int i = 0; i < times; ++i)
	{
		cout << str.str << endl;
	}
}

static void show(const char* str, int times = 1)
{
	for(int i = 0; i < times; ++i)
	{
		cout << str << endl;
	}
}

int main(void)
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
	return 0;
}
