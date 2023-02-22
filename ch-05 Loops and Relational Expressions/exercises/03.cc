#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	int sum = 0;
	int i;
	cin >> i;
	while(i != 0)
	{
		sum += i;
		cout << "cumulative sum of the entries to date: " << sum << endl;
		cin >> i;
	}
	return 0;
}
