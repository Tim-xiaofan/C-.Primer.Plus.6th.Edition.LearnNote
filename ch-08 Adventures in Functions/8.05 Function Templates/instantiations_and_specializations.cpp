/*20210116 18:15,zyj,GuangDong*/
// twotemps.cpp -- using overloaded template functions
#include <iostream>
template <typename T> // original template
void Swap(T &a, T &b);
template <> void Swap<int>(int &, int &); // explicit specialization
template <> void Swap(int &, int &); // explicit specialization
template void Swap<int>(int&, int&); // explicit instantiation

int main()
{
	return 0;
}

template <> void Swap<int>(int &i, int &j) // explicit specialization
{
	using namespace std;
	cout <<"explicit specialization NO.one is executed------" << endl;
	int temp = i;
	i = j;
	j = temp;
}

//error:redifinition
template <> void Swap(int &i, int &j) // explicit specialization
{
	using namespace std;
	cout <<"explicit specialization NO.two is executed------" << endl;
	int temp = i;
	i = j;
	j = temp;
}
