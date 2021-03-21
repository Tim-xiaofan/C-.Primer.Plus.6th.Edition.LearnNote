/* 20210321 20:31, zyj, GuangDong*/
//variadic1.cpp -- using recursion to unpack a parameter pack
#include <iostream>
#include <string>

// definition for 0 parameters -- terminating call
void show_list3()
{

}

template<typename T>
void show_list3(const T & value)
{
	std::cout << value << std::endl;
}

// definition for 1 or more parameters
template<typename T, typename... Args>
void show_list3(const T & value, const Args&... args)
{
	std::cout << value << ", ";
	show_list3(args...);
}

int main()
{
	int n = 14;
	double x = 2.71828;
	std::string mr = "Mr. String objects!";
	show_list3(n, x);
	show_list3(x*x, '!', 7, mr);
	return 0;
}
