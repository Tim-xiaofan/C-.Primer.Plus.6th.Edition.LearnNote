/* 20210303 20:52, zyj, GuangDong*/
// strf_relation.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
int main()
{
	using namespace std;

	string snake1("cobra");
	string snake2("coral");
	char snake3[20] = "anaconda";
	if (snake1 < snake2) // operator<(const string &, const string &)
	  cout << snake1<< "<" << snake2 << endl;
	if (snake1 == snake3) // operator==(const string &, const char *)
	  cout << snake1 << "=" << snake3 << endl;
	if (snake3 != snake2) // operator!=(const char *, const string &)
	  cout << snake3 << "!=" << snake2 << endl;
	cout << "0 = " << (int) '0' << endl;
	cout << "A = " << (int) 'A' << endl;
	cout << "a = " << (int) 'a' << endl;
}
