#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <fstream>

using std::cout;
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

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(-1);
	}
	std::ifstream fin(argv[1]);
	if(fin)
	{
		int num;
		fin >> num;
		fin.ignore(2048, '\n');
		vector<struct contributor> contributors(num);
		for(struct contributor& c: contributors)
		{
			getline(fin, c.name);
			fin >> c.contribution;
			fin.ignore(2048, '\n');
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
	}
	return 0;
}
