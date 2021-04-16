/** 20210416 14:34, zyj, GuangDong*/
//fasparam.cpp --functor as parameter

#include <iostream>

using std::cout;
using std::endl;

template<typename UnaryOperator>
void foo(const UnaryOperator & fun)
{
	int a = 0;
    fun(a);
}

void f(int a) {cout << a <<" funtion \n";}

struct G
{
    void operator()(int a) const {cout << a <<" functor\n";}
};

int main()
{
	foo(f);
	foo(G());
	return 0;
}
