#include <iostream>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

template<typename T, int n>
using arrayn = T [n];

template<typename T, int n>
T maxn(const arrayn<T, n>& a)
{
	static_assert(n > 0);
	T max =  a[0];
	for(int i = 1; i < n; ++i)
	{
		if(max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

template<int n>
size_t maxn(const arrayn<const char*, n>& a)
{
	static_assert(n > 0);
	size_t max = strlen(a[0]);
	for(int i = 0; i < n; ++i)
	{
		size_t len = strlen(a[i]);
		if(max < len)
		{
			max = len;
		}
	}
	return max;
}

int main(void)
{
	arrayn<int, 6> a = {5, 2, 4, 6, 1, 3};
	cout << "max int: " << maxn(a) << endl;
	arrayn<double, 4> b = {5, 2, 4, 6};
	cout << "max double: " << maxn(b) << endl;
	arrayn<const char*, 5> c = {"123", "abcdf", "ashs", "123", "aaaaa"};
	cout << "max strlen: " << maxn(c) << endl;
	return 0;
}
