#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

template<typename T>
using array5 = T [5];

template<typename T>
T max5(const array5<T>& a)
{
	T max =  a[0];
	for(int i = 1; i < 5; ++i)
	{
		if(max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

int main(void)
{
	array5<int> a = {5, 2, 4, 6, 1};
	cout << "max int: " << max5(a) << endl;
	array5<double> b = {5, 2, 4, 6, 1};
	cout << "max double: " << max5(b) << endl;
	return 0;
}
