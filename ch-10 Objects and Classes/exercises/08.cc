#include <iostream>
#include <string>

#include "list.h"

using std::cout;
using std::endl;
using std::string;

template<typename T>
void print(const exercises::list<T>& l)
{
	for(typename exercises::list<T>::const_iterator p = l.begin();
				p != l.end();
				++p)
	{
		cout << *p << " ";
	}
	cout << endl;
}

int main(void)
{
	int a[4] = {0, 1, 2, 3};
	exercises::list<int> l;
	print(l);
	cout << "empty: " << std::boolalpha << l.empty()  << endl;
	cout << "full: " << std::boolalpha << l.full()  << endl;
	l.add(a, 4);
	print(l);
	cout << "empty: " << std::boolalpha << l.empty()  << endl;
	cout << "full: " << std::boolalpha << l.full()  << endl;
	l.add(a, 4);
	print(l);
	cout << "empty: " << std::boolalpha << l.empty()  << endl;
	cout << "full: " << std::boolalpha << l.full()  << endl;

	for(auto p = l.begin(); p != l.end(); ++p)
	{
		*p += 1;
	}
	print(l);

	const auto p = l.begin();
	cout << *p << endl;

	return 0;
}
