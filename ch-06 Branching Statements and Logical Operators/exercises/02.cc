#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static const int N = 10;

int main(void)
{
	double sum = 0;
	double donation[N];

	int i;
	for(i = 0; i < N && (cin >> donation[i]); ++i)
	{
		sum += donation[i];
	}

	if(i > 0)
	{
		double average = sum / i;
		cout << "average: " << average << endl;

		int ct = 0;
		for(int j = 0; j < i; ++j)
		{
			if(donation[j] > average)
			{
				++ct;
			}
		}
		cout << ct << " numbers in the array are larger than the average." << endl;
	}
	return 0;
}
