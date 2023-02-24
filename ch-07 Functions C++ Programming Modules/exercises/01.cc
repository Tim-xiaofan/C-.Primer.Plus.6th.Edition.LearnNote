#include <iostream>

using std::cout;
using std::endl;
using std::cin;

double harmonic_mean(double x, double y)
{
	return 2.0 * x * y / (x + y);
}

int main(void)
{
	double x, y;
	cout << "Enter x y : ";
	while((cin >> x >> y) && (x != 0.0 && y != 0.0))
	{
		cout << harmonic_mean(x, y) << endl;
		cout << "Enter x y : ";
	}
	return 0;
}
