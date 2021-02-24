/** 20210222 21:57, zyj, GuangDong*/
//error1.cpp -- using the abort() function
#include <iostream>
#include <cstdlib>
double hmean(double a, double b);

int main()
{
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

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";
		throw "bad hmean() arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b);
}
