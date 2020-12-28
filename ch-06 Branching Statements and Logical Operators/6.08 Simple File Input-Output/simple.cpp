/*20201228 09:04,zyj,GuangDong*/
// simple.cpp 
#include <iostream>

int main(int argc, char *argv[])
{
	using namespace std;
	cout << "Enter something:" << endl;
	int ch;
	cin >> ch;
	while(1)
	{
		if(cin.fail()) 
		{
			cout << "cin failed" << endl;
			//cin.clear();
			break;
		}
		else 
		  cout << ch << endl;
		cin >> ch;
	}
	return 0;
}
