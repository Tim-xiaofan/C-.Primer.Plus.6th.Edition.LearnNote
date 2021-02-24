/** 20210224 12:57, zyj, GuangDong*/
// main.cpp -- nested exceptions
#include "sales.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	Sales sales(9.15);
	LabeledSales lsales("233", 9);
	try
	{
		//cout << sales[19] << endl;
		cout << lsales[19] << endl;
	}
	catch(LabeledSales::nbad_index & nbi)
	{
		cout << nbi.what() << endl;
	}
	catch(Sales::bad_index & bi)
	{
		cout << bi.what() << endl;
	}
}
