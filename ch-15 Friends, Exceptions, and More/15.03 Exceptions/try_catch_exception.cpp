/** 20210223 21:34, zyj, GuangDong*/
//try_catch_exception.cpp -- The exception Class
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <exception>
double hmean(double a, double b);
double gmean(double a, double b);

class bad_hmean : public std::exception
{
	public:
		const char * what() { return "bad arguments to hmean()"; }
};
class bad_gmean : public std::exception
{
	public:
		const char * what() { return "bad arguments to gmean()"; }
};

int main()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x,y);
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x,y) << std::endl;
			std::cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean &e) // start of exception handler
		{
			std::cout << e.what() << std::endl;
			break;
		}
		catch (bad_gmean &e) // end of exception handler
		{
			std::cout << e.what() << std::endl;
			break;
		}
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean();
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a * b < 0)
	{
		throw bad_gmean();
	}
	return std::sqrt(a * b);
}
