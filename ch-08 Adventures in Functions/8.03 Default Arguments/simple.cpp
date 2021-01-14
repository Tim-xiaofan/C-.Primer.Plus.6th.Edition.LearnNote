/*20210114 12:47,zyj,GuangDong*/
#include <iostream>
using namespace std;
int harpo(int n, int m = 4, int j = 5); // VALID
//int chico(int n, int m = 6, int j); // INVALID
int groucho(int k = 1, int m = 2, int n = 3); // VALID

int main()
{
	int beeps;
	beeps = harpo(2); // same as harpo(2,4,5)
	beeps = harpo(1,8); // same as harpo(1,8,5)
	beeps = harpo (8,7,6); // no default arguments used
	return 0;
}

int harpo(int n, int m, int j)
{
	cout << "harpo:";
	cout << "arg1 = " << n;
	cout << ", arg2 = " << m;
	cout << ", arg3 = " << j << endl;
	return n;
}
