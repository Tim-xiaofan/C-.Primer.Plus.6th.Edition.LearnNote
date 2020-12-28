/*20201227 17:45,zyj,GuangDong*/
// simple.cpp 
#include <iostream>

int main(int argc, char *argv[])
{
	using namespace std;
	cout << "Enter something:" << endl;
	int n;
	cin >> n;
	if(cin.fail()) cout << "cin failed" << endl;
	else cout << n << endl;
	return 0;
}
