/** 20210218 19:13, zyj, GuangDong*/
#include <iostream>
#include <string>
#include "arraytp.h"
#define N 10

static int array[N] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
static std::string array1[N] = {"1", "2", "4", "8", "16", "32",
	"64", "128", "256", "512"};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	ArrayTP<int, N> ai(array, N - 5);
	int i;
	for(i = 0; i < N; i++)
	  cout << ai[i] << " ";
	cout << endl;

	ArrayTP<std::string, N> as(array1, N - 6);
	for(i = 0; i < N; i++)
	  cout << as[i] << ",";
	cout << endl;
}
