#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

static const int strsize = 32;

// Benevolent Order of Programmers name structure
struct bop {
	string fullname; // real name
	string title; // job title
	string bopname; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

enum {BYNAME, BYTITLE, BYBOPNAME, BYPREFERENCE};
static void display_by(const vector<struct bop>& bops, int by)
{
	switch(by)
	{
		case BYNAME:
			for(const struct bop& b: bops)
			{
				cout << b.fullname << endl;
			}
			break;
		case BYTITLE:
			for(const struct bop& b: bops)
			{
				cout << b.title << endl;
			}
			break;
		case BYBOPNAME:
			for(const struct bop& b: bops)
			{
				cout << b.bopname << endl;
			}
			break;
		case BYPREFERENCE:
			for(const struct bop& b: bops)
			{
				if(b.preference == 0)
				{
					cout << b.fullname << endl;
				}
				else if(b.preference == 1)
				{
					cout << b.bopname << endl;
				}
				else
				{
					cout << b.title << endl;
				}
			}
			break;
	}
}

int main(void)
{
	vector<struct bop> bops = {
		{"Wimp Macho", "t1","WM", 0},
		{"Raki Rhodes",  "t2", "RR", 1},
		{"Celia Laiter", "t3", "CL", 2},
		{"Hoppy Hipman", "t4", "HH", 0},
		{"Pat hand", "t5", "PH", 1}
	};

	cout << "a. display by name b. display by title\n"
		"c. display by bopname d. display by preference\nq. quit\n";

	char ch;
	cout << "Enter your choice: ";
	while((cin >> ch) && (ch != 'q'))
	{
		switch(ch)
		{
			case 'a':
				display_by(bops, BYNAME);
				break;
			case 'b':
				display_by(bops, BYTITLE);
				break;
			case 'c':
				display_by(bops, BYBOPNAME);
				break;
			case 'd':
				display_by(bops, BYPREFERENCE);
				break;
			default:
				cout << endl;
		}
		cout << "Next choice: ";
	}
	cout << "Bye!\n";
	return 0;
}
