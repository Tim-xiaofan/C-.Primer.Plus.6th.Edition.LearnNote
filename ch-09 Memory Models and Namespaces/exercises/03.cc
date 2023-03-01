/*20230228 20:58,zyj,GuangDong*/
// 03.cpp
#include <iostream>
#include <new>
#include <cstdio>

using std::cout;
using std::endl;

struct chaff
{
	char dross[20];
	int slag;
};

const int N = 2;

static char buffer[sizeof(chaff)*N];

int main(void)
{
	chaff *chaffs = new(buffer) chaff[N];
	for(int i = 0; i < N; ++i)
	{
		snprintf(chaffs[i].dross, 20, "dross%d", i);
		chaffs[i].slag = i;
	}
	for(int i = 0; i < N; ++i)
	{
		cout << chaffs[i].dross << ", "
			<< chaffs[i].slag << endl;
	}
	return 0;
}
