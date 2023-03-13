/** 20210222 22:29, zyj, GuangDong, 20230313 11:20*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;

double hmean(double a, double b);
double gmean(double a, double b);

class bad_hmean : public std::logic_error
{
	public:
		bad_hmean(const string& what_arg="")
			:std::logic_error(what_arg) {}
		const char* what() const noexcept override
		{
			return "invalid arguments for hmean"; 
		}
};

class bad_gmean : public std::logic_error
{
	public:
		bad_gmean(const string& what_arg = "")
			:std::logic_error(what_arg){}
		const char* what() const noexcept override
		{
			return "invalid arguments for gmean"; 
		}
};

int main()
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_gmean & bg) // start of exception handler
		{
			cout << bg.what() << endl;
			cout << "\nSorry, you don't get to play any more.\n";
			break;
		}
		catch (bad_hmean & bh) 
		{
			cout << bh.what() << endl;
			cout << "Enter next set of numbers <q to quit>: ";
			continue;
		} // end of handler
	}
	cout << "Bye!\n";
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
