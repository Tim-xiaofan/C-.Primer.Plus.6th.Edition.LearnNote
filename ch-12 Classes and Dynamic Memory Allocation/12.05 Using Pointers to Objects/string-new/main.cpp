/** 20210202 21:40,zyj,GuangDong*/
// compile with string1.cpp
#include <iostream>
#include "string.h"
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	String *name = new String("Tom");
	cout << "*name = " << *name << endl;
	String *name1  = new String(*name);
	cout << "*name1 = " << *name1 << endl;
	String *name3 = new String;
	delete name;
	delete name1;
	delete name3;
	name = name1 = name3 = nullptr;
	return 0;
}
