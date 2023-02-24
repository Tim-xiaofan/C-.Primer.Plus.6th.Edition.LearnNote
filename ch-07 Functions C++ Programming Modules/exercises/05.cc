#include <iostream>

using std::cout;
using std::endl;
using std::cin;

unsigned long long factorial(unsigned long long n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main(void)
{
	unsigned long long n;
	cout << "Enter the number: ";
	while(cin >> n)
	{
		cout << "factorial: " << factorial(n) << endl;
		cout << "Next number: ";
	}
	return 0;	
}
