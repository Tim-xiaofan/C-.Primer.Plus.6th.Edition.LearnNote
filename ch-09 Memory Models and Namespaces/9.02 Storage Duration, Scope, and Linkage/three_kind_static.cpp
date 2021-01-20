/*20210118 22:40,zyj,GuangDong*/
#include <iostream>
using namespace std;

int global = 1000; // static duration, external linkage
static int one_file = 50; // static duration, internal linkage
void funct1(int n);

int main()
{
	int i;
	for(i = 0; i < 10; i++)
	  funct1(0);
	return 0;
}

void funct1(int n)
{
	static int count = 0; // static duration, no linkage
	int llama = 0, i;
	cout << "funct1: count = " << count++ << endl;
}
