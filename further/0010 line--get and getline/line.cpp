/** 202101021 14:31, zyj, GuangDong*/
//get.cpp -- read a line
/**
  get(char*, int)	Sets failbit if no characters are read.
 */
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;

const int BUF_SZ = 40;
const char *file = "line.cpp";

int main(int ac, char * av[])
{
	char line[BUF_SZ];
	std::fstream fin;
	std::ios_base::iostate state;

	cout << "buf size is " << BUF_SZ << endl;
	cout << "=======get" << endl;
	fin.open(file);
	while(fin.get(line, BUF_SZ))//end when reaching empty line or EOF
	{
		cout << line << endl;
		fin.get(); // read newline
	}
	if(!fin)
	{
	  state = fin.rdstate();
	  if(!(state & std::ios_base::eofbit))
	  {
		  cout << "not reached end of file\n";
		  if(state & std::ios_base::failbit)
		  {
			  cout << "get reached enpty line\n";
		  }
	  }
	}
	fin.close();
	fin.clear();

	fin.open(file);
	cout <<  endl << endl << "=======getline" << endl;
	while(fin.getline(line, BUF_SZ))//end when reached EOF or line's length exceeds buf size
	{
		cout << line << endl;
	}
	if(!fin)
	{
	  state = fin.rdstate();
	  if(!(state & std::ios_base::eofbit))
	  {
		  cout << "not reached end of file\n";
		  if(state & std::ios_base::failbit)
		  {
			  cout << "line length exceeds buf size\n";
		  }
	  }
	}
	fin.close();
	return 0;
}
