#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

static double* fill_array(double* begin, double* end)
{
	cout << "Enter numbers: ";
	while((begin != end) && (cin >> *begin))
	{
		++begin;
	}
	if(!cin)
	{
		cin.clear();
	}
	while(cin.get() != '\n');
	return begin;
}

static void show_array(const double* begin, const double* end)
{
	std::for_each(begin, end, [](double d) { cout << d << " ";});
	cout << endl;
}

static void revalue(double* begin, double* end, double r)
{
	std::for_each(begin, end, [r](double& d) { d = r; });
}

static const int N = 5;

int main(void)
{
	double arr[N];
	double* actual_end = fill_array(arr, arr + N);
	cout << "origin: ";
	show_array(arr, actual_end);
	double r;
	cout << "enter r to revalue: ";
	cin >> r;
	cout << "after revalue to " << r <<": ";
	revalue(arr, actual_end, r);
	show_array(arr, actual_end);
	return 0;	
}
