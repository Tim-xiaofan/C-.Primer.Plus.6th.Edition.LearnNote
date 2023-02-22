#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	cout << "Enter first: ";
	int fisrt;
	cin >> fisrt;

	cout << "Enter last: ";
	int last;
	cin >> last;

	{
		long sum = 0;
		for(int i = fisrt; i <= last; ++i)
		{
			sum += i;
		}
		cout << "sum: " << sum << endl;
	}

	{
		long n = last + 1 - fisrt;
		assert(n > 0);
		cout << "sum: " << (fisrt + last) * n / 2 << endl;
	}
	return 0;
}
