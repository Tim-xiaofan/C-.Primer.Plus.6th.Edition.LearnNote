/* 20210315 22:12, zyj, GuangDong*/
// count.cpp -- counting characters in a list of files
#include <iostream> // not needed for many systems
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	using namespace std;
	
	int count, i, total = 0;
	ifstream fin;
	char ch;

	for(i = 1; i < argc; i++)
	{

		fin.open(argv[i]);
		if(!fin.is_open())
		{
			cout << "cannot open file : " << argv[i];
			continue;
		}

		count = 0;
		while(fin.get(ch)) count++;

		cout << count << " characters in " 
			<< argv[i] << endl;
		total += count;
		
		fin.close();
		fin.clear();
	}

	cout << total << " characters in all files\n";
	return 0;
}
