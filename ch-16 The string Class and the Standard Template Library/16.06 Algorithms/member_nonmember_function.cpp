/* 20210312 12:29, zyj, GuangDong*/
// listrmv.cpp -- applying the STL to a string
#include <iostream>
#include <list>
#include <algorithm>

void Show(int);
const int LIM = 10;

int main()
{
	using namespace std;
	int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "Original list contents:\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << "\nsize = " << la.size()<< endl << endl;

	la.remove(4);
	cout << "After using the remove() method:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << "\nla size = " << la.size()<< endl << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "After using the remove() function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << "\nlb size = " << lb.size()<< endl << endl;

	lb.erase(last, lb.end());
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << "\nlb size = " << lb.size()<< endl << endl;
	return 0;
}

void Show(int v)
{
	std::cout << v << ' ';
}
