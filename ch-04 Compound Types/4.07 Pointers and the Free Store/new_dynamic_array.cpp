/*20201221 22:40,zyj,GuangDong */
// new_dynamic.cpp -- using the new operator to create dynamic array
#include <iostream>
int main()
{
	using namespace std;
	int *things =  new int[10];
	int *things1 =  new int[10]();
	int i;
	for(i = 0; i< 10; i++)
	  cout << things[i] << " ";
	cout << endl;
	for(i = 0; i< 10; i++)
	  cout << things1[i] << " ";
	cout << endl;
	delete[] things;
	things = NULL;
	//delete things1;// effect is undefined, don't do i(编译器无警告)
	return 0;
}
