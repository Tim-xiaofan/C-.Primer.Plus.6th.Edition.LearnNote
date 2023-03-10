/* 20210225 21:19, zyj, GuangDong*/
//try_catch_unexpected.cpp -- change unexpected exception behavor(default abort())
#include <iostream>
#include <cstdlib>
#include <exception>
/** exception specifications*/
double hmean(double a, double b) throw(const char *);

/**note: must shutdwon , or undefined behavor*/
void my_unexpected()
{
	std::cout << "my_unexpected: Terminating due to unexpected exception\n";
	throw std::bad_exception();
}

int main()
{
	std::set_unexpected(my_unexpected);
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x,y);
		}
		catch (const char * s) // start of exception handler
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";
			continue;
		} // end of handler
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

#define UNEXPECTED

double hmean(double a, double b) throw(const char *)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";
#ifndef UNEXPECTED
		throw "bad hmean() arguments: a = -b not allowed";
#else 
		throw -1;
#endif
	}
	return 2.0 * a * b / (a + b);
}
