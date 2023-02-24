#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

static int fill_array(double arr[], int n)
{
	int ct = 0;
	while(n-- && (cin >> arr[ct]))
	{
		++ct;
	}
	if(!cin)
	{
		cin.clear();
	}
	while(cin.get() != '\n');
	return ct;
}

static void show_array(const double arr[], int n)
{
	std::for_each(arr, arr + n, [](double d) { cout << d << " ";});
	cout << endl;
}

static void reverse_array(double arr[], int n)
{
	for(int i = 0, j = n - 1; i < j; ++i, --j)
	{
		std::swap(arr[i], arr[j]);
	}
}

static const int N = 5;

int main(void)
{
	double arr[N];
	int actual_number = fill_array(arr, N);
	cout << "original: ";
	show_array(arr, actual_number);
	cout << "after reversing all: ";
	reverse_array(arr, actual_number);
	show_array(arr, actual_number);
	cout << "after reversing all but the first and last: ";
	reverse_array(arr + 1, actual_number - 2);
	show_array(arr, actual_number);

	return 0;	
}
