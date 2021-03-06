/* 20210306 16:11, zyj, GuangDong*/
// uniqueptr_variant.cpp -- a delete[] version of unique_ptr
#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
	using namespace std;
	std::unique_ptr< double[]>pda(new double[5]); // will use delete []
	int i;
	for(i = 0; i < 5; i++)
	  cout << "#" << i << " " << pda[i] << endl;
	unique_ptr<string []> psa (new string[5]);
	psa[0] = "string0";
	psa[1] = "string1";
	psa[2] = "string2";
	psa[3] = "string3";
	psa[4] = "string4";
	for(i = 0; i < 50; i++)
	  cout << "#" << i << " " << psa[i] << endl;
}
