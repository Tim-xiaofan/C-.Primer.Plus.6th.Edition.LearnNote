/*20201222 12:30,zyj,GuangDong*/
// array_name.cpp -- what an array's name interprets
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	short tell[10]={1}; // tell an array of 20 bytes
	cout << "tell:"<< tell << " sizeof(tell):"<< sizeof(tell) << endl; // displays &tell[0]
	cout << "&tell:"<< &tell << " sizeof(&tell):"<< sizeof(&tell) << endl; // displays address of whole array
	short (*pas)[10] = &tell; // pas points to array of 20 shorts
	cout << "*pas:"<< *pas << " sizeof(*pas):"<< sizeof(*pas) << endl; 
	return 0;
}
//tell:0xffffc402daa0 sizeof(tell):20
//&tell:0xffffc402daa0 sizeof(&tell):8
//*pas:0xffffc402daa0 sizeof(*pas):20
