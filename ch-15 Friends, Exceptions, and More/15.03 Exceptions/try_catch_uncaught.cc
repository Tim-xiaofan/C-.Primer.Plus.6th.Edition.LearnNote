/* 20230310 15:25, zyj, GuangDong*/
//try_catch_uncaught.cpp -- change uncaught exception behavor(default abort())
#include <iostream>
#include <cstdlib>
#include <exception>
/** exception specifications*/
double hmean(double a, double b) throw(const char *);

/**note: must shutdwon , or undefined behavor*/
void myQuit()
{
	std::cout << "myQuit:Terminating due to uncaught exception\n";
	exit(5);
}

int main()
{
	std::set_terminate(myQuit);
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x,y);
		}
		catch (int e) // start of exception handler
		{
			std::cout << e << std::endl;
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


double hmean(double a, double b) throw(const char *)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";
		throw "bad hmean() arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b);
}
