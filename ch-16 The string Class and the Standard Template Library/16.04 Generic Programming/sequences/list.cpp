/* 20210309 21:06, zyj, GuangDong*/
// list.cpp -- usage of list container
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
void outint(int n) {std::cout << n << " ";}

int main()
{
	using namespace std;
	list<int> one(5, 2); // list of 5 2s
	int stuff[5] = {1, 2, 4, 8, 6};
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5 );
	int more[6] = {6, 4, 2, 4, 6, 5};
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";
	for_each(one.begin(),one.end(), outint);
	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "List three: ";
	for_each(three.begin(), three.end(), outint);

	three.remove(2);
	cout << endl << "after minus 2s, List three : ";
	for_each(three.begin(), three.end(), outint);

	three.splice(three.begin(), one);
	cout << endl << "after splice one at start, List three : ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "after splice one at List three start, List one: ";
	for_each(one.begin(), one.end(), outint);

	three.unique();
	cout << endl << "after unique, List three: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "after sort & unique, List three : ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged into three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	list<int> four = {1, 2, 2, 3 ,4, 3, 2, 4, 1};
	cout << "List four : ";
	for_each(four.begin(), four.end(), outint);
	cout << endl;
	four.unique();
	cout << "after unique, List four : ";
	for_each(four.begin(), four.end(), outint);
	cout << endl;
	four.sort();
	cout << "after sort, List four : ";
	for_each(four.begin(), four.end(), outint);
	cout << endl;
	four.unique();
	cout << "after unique again, List four : ";
	for_each(four.begin(), four.end(), outint);
	cout << endl;
	return 0;
}
