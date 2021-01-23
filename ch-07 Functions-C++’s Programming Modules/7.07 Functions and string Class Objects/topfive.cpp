/*20210105 21:27,zyj,GuangDong*/
// topfive.cpp -- handling an array of string objects
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);

int main(int argc, char *argv[])
{
	string list[SIZE]; // an array holding 5 string object
	int i = 0;
	cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
	{
		cout << i + 1 << ": ";
		getline(cin,list[i]);
	}
	cout << "Your list:\n";
	display(list, SIZE);
	return 0;
}

void display(const string sa[], int n)
{
	for (int i = 0; i < n; i++)
	  cout << i + 1 << ": " << sa[i] << endl;
}
