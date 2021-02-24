/** 20210222 21:40, zyj, GuangDong*/
//error1.cpp --  -- returning an error code
#include <iostream>
#include <cstdlib>
#include <cfloat>
bool hmean(double a, double b, double *ans);

int main()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if(hmean(x, y, &z))
		{
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;
		}
		else
		  std::cout << "One value should not be the negative "
			  << "of the other - try again.\n";
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

bool hmean(double a, double b, double *ans)
{
	if (a == -b)
	{
		//std::cout << "untenable arguments to hmean()\n";
		//std::abort();
		*ans = DBL_MAX; 
		return false;
	}
	
	*ans = 2.0 * a * b / (a + b);
	return true;
}
