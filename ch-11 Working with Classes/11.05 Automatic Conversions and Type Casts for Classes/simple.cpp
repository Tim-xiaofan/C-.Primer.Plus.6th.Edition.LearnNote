/** 20210130 16:50,zyj,GunagDong*/
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	long count = 8; /** int value 8 converted to type long */
	double time = 11; 
	int side = 3.33; 

	//int * p = 10; // type clash
	int * p = (int *)10;
	//cout << "*p = " << *p << endl; /** segement fault */ 
	cout << "p = " << p << endl; 
	cout << "p * p = " << p * p << endl; 
}
