/** 20210222 22:29, zyj, GuangDong*/
//error4.cpp -- using the abort() function
#include <iostream>
#include <cstdlib>
#include <cmath>
double hmean(double a, double b);
double gmean(double a, double b);

class bad_hmean
{
	private:
		double v1;
		double v2;
	public:
		bad_hmean(double a = 0, double b = 0) : v1(a), v2(b){}
		void mesg();
};
inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 <<"): "
		<< "invalid arguments: a = -b\n";
}

class bad_gmean
{
	public:
		double v1;
		double v2;
		bad_gmean(double a = 0, double b = 0) : v1(a), v2(b){}
		const char * mesg();
};
inline const char * bad_gmean::mesg()
{
	return "gmean() a * b not >= 0\n";
}

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
		catch (bad_gmean & bg) // start of exception handler
		{
			bg.mesg();
			std::cout << "Sorry, you don't get to play any more.\n";
			break;
		}
		catch (bad_hmean & bh) 
		{
			bh.mesg();
			std::cout << "Enter next set of numbers <q to quit>: ";
			continue;
		} // end of handler
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a * b < 0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a * b);
}
