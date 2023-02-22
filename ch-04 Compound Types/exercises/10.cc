#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

int main(void)
{
	const int n = 3;
	array<float, n> dash;
	for(int i = 0; i < n; ++i)
	{
		cout << "Enter " << (i + 1) << " dash: ";
		cin >> dash[i];
	}

	float sum = 0;
	for(float f: dash)
	{
		cout << f << endl;
		sum += f;
	}

	cout << "average: " << (sum / n) << endl;

	return 0;
}
