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

class bad_base : public std::logic_error
{
	public:
		bad_base(double x, double y, const string& what_arg="")
			:logic_error(what_arg), x_(x), y_(y), message_("")
		{}
		virtual ~bad_base() = 0;
		virtual const char* what() const noexcept override 
		{ return ""; }
	protected:
		double x_;
		double y_;
		mutable string message_;
};

bad_base::~bad_base()
{}

class bad_hmean :public bad_base
{
	public:
		bad_hmean(double x, double y)
			:bad_base(x, y) {}
		~bad_hmean() {}
		const char* what() const noexcept override
		{
			message_ = "invalid arguments(x=" + std::to_string(x_) + ", y=" + std::to_string(y_) + ") for hmean"; 
			return message_.data();
		}
};

class bad_gmean : public bad_base
{
	public:
		bad_gmean(double x, double y)
			:bad_base(x, y){}
		~bad_gmean() {}
		const char* what() const noexcept override
		{
			message_ = "invalid arguments(x=" + std::to_string(x_) + ", y=" + std::to_string(y_) + ") for gmean"; 
			return message_.data();
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
			z = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << z << endl;
		}
		catch (bad_base & e) // start of exception handler
		{
			cout << e.what() << endl;
			break;
		}
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye!\n";
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
