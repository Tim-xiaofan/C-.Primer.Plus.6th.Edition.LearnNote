#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct contributor
{
	string name;
	double contribution;
};

static void print(const struct contributor& c)
{
	cout << c.name << ", " << c.contribution << endl;
}

int main(void)
{
	int num;
	cout << "Enter number of contributors: ";
	cin >> num;
	cin.ignore(2048, '\n');
	vector<struct contributor> contributors(num);
	int i = 0;
	for(struct contributor& c: contributors)
	{
		cout << "Contributor #" << ++i << endl;
		cout << "Enter name: ";
		getline(cin, c.name);
		cout << "Enter contribution: ";
		cin >> c.contribution;
		cin.ignore(2048, '\n');
	}
	cout << "\nGrand Patrons" <<endl;
	int ct = 0;
	std::for_each(contributors.begin(),
				contributors.end(),
				[&ct](const struct contributor& c)
				{ if(c.contribution >= 10000) { print(c); ++ct;}} );
	if(ct == 0)
	{
		cout << "none." << endl;
	}

	ct = 0;
	cout << "\nPatrons" << endl;
	std::for_each(contributors.begin(),
				contributors.end(),
				[&ct](const struct contributor& c)
				{ if(c.contribution < 10000) { print(c); ++ct;}} );
	if(ct == 0)
	{
		cout << "none." << endl;
	}
	return 0;
}
