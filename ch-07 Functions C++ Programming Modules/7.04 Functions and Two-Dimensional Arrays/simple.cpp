/*20210104 12:54,zyj,GuangDong*/
// simple.cpp 
#include <iostream>

int array_sum(int arr[][4], unsigned int size);

int main(int argc, char *argv[])
{
	using namespace std;
	int a[3][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}};
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(a[0]) = " << sizeof(a[0]) << endl;
	int i;
	for(i = 0; i < 3; i++)
		cout << "&a[" << i << "] = " << &a[i] << endl;
	cout << "sum = " << array_sum(a, 3) << endl;
	return 0;
}

int array_sum(int arr[][4], unsigned int size)
{
	int i, j, sum = 0;
	for(i = 0; i < size; i++)
	  for(j = 0; j < 4; j++)
		sum += arr[i][j];
	return sum;
}
