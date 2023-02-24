#include <iostream>

using std::cout;
using std::endl;
using std::cin;

static void
input(double arr[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << "input ["<< i <<"]: ";
		cin >> arr[i];
	}
}

static double
average(const double arr[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	return sum / n;
}

static void
print(const double arr[],  int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

const int N = 10;

int main(void)
{
	double arr[N];
	input(arr, N);
	cout << "scores: ";
	print(arr, N);
	cout << "average score: " << average(arr, N) << endl;
	return 0;
}
