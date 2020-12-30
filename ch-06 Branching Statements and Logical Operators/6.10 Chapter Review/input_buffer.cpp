/* 20201228 22:41,zyj,GuangDong*/
// input_buffer.cpp 
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	char ch;
	int ct1, ct2;
	ct1 = ct2 = 0;
	while ((ch = cin.get()) != '$')
	{
		cout << ch;
		ct1++;
		//if (ch == '$')
		//  ct2++;
		//cout <<"("<< ch << ")";
	}
	cout << endl <<"ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";
	return 0;
}

//input：
//Hi!
//Send $10 or $20 now!

//output:
//H$i$!$
//$S$e$n$d$ $
//ct1 = 9, ct2 = 9
