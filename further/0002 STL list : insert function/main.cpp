/** 20210401 11:16, zyj, GuangDong*/
// list_class_insert.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	list <int> c1, c2;
	list <int>::iterator Iter;

	c1.push_back(10);
	c1.push_back(20);
	c1.push_back(30);
	c2.push_back(40);
	c2.push_back(50);
	c2.push_back(60);

	cout << "c1 =";
	for (auto c : c1)
	  cout << " " << c;
	cout << endl;

	Iter = c1.begin();
	Iter++;
	c1.insert(Iter, 100);
	cout << "c1 =";
	for (auto c : c1)
	  cout << " " << c;
	cout << endl;

	Iter = c1.begin();
	Iter++;
	Iter++;
	c1.insert(Iter, 2, 200);

	cout << "c1 =";
	for(auto c : c1)
	  cout << " " << c;
	cout << endl;

	c1.insert(++c1.begin(), c2.begin(), --c2.end());

	cout << "c1 =";
	for (auto c : c1)
	  cout << " " << c;
	cout << endl;

	// initialize a list of strings by moving
	list < string > c3;
	string str("a");

	c3.insert(c3.begin(), move(str));
	cout << "Moved first element: " << c3.front() << endl;

	// Assign with an initializer_list
	list <int> c4{ {1, 2, 3, 4} };
	c4.insert(c4.begin(), { 5, 6, 7, 8 });

	cout << "c4 =";
	for (auto c : c4)
	  cout << " " << c;
	cout << endl;
}
