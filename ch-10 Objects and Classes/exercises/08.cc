#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

#include "list.h"

using std::cout;
using std::endl;
using std::string;

template<typename T>
void print(const exercises::list<T>& l)
{
	static_assert(std::is_same<decltype(*l.begin()), const T&>::value);
	std::copy(l.begin(), l.end(), std::ostream_iterator<T>(std::cout, " "));
	cout << endl;
}

int main(void)
{
	int a[4] = {0, 1, 2, 3};

	{
		cout << "test int" << endl;
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
		std::for_each(l.begin(), l.end(), [](int &i) { i+=1;});
		print(l);
	}

	{
		cout << "\ntest const int\n";
		exercises::list<const int> l;
		static_assert(std::is_same<decltype(*l.begin()), const int&>::value);
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

		auto it = l.begin();
		//*it = 10; //compile error
	}


	{
		cout << "\ntest const int* i" << endl;;
		exercises::list<int> l;
		l.add(a, 4);
		const int *pi = &a[0];
		//*pi = 10; // compile error
		cout << *pi << endl;
		const exercises::list_iterator<int> it = l.begin();
		//*it = 10; // compile error
		cout << *it << endl;
	}

	return 0;
}
