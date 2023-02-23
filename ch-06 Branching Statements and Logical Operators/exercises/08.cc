#include <iostream>
#include <fstream>
#include <cstdio>

using std::cout;
using std::endl;

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
		int ct = 0;
		while(fin.get() && fin)
		{
			++ct;
		}
		cout << ct << " characters in the file." << endl; 
	}
	else
	{
		fprintf(stderr, "failed to open file: %s\n", argv[1]);
	}
	return 0;
}
