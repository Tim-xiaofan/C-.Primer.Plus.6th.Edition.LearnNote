/* 20210306 16:11, zyj, GuangDong*/
// smrtptrs_select.cpp 
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <ctime>

using namespace std;

unique_ptr<int> make_int(int n)
{
	return unique_ptr<int>(new int(n));
}
void show(unique_ptr<int> & pi) // pass by reference
{
	cout << *pi << ' ';
}

int main()
{
	const int size = 9;
	vector<unique_ptr<int> > vp(size);
	uint32_t i;
	srand(time(NULL));
	for (i = 0; i < vp.size(); i++)
	  vp[i] = make_int(rand() % 1000); // copy temporary unique_ptr
	vp.push_back(make_int(rand() % 1000)); // ok because arg is temporary
	for_each(vp.begin(), vp.end(), show); // use for_each()
	cout << "\n";
}
