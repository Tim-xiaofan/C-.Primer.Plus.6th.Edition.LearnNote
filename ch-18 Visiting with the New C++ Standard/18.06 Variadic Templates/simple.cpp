/* 20210321 20:18, zyj, GuangDong*/
// simple.cpp 
#include <iostream>
#include <cstring>
using namespace std;

/** 无法工作：无穷循环*/
template<typename... Args> // Args is a template parameter pack
void show_list1(Args... args) // args is a function parameter pack
{
	show_list1(args...); // passes unpacked args to show_list1()
}

int main()
{
	return 0;
}
