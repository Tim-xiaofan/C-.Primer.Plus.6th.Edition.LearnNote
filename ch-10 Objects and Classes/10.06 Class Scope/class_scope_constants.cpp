/*20210126 21:21,zyj,GuangDong*/
// class_scope_constants.cpp -- constants shared by all object
// version 00
#include <iostream>
#define RUN 1
#define TEST 1

class Bakery
{
#ifndef RUN
	private:
		const int Months = 12; // declare a constant? FAILS
		double costs[Months];
#endif
};

/*first way*/
class Bakery1
{
#ifdef TEST
	public:
#else
	private:
#endif
		enum {Months = 12}; // successful
		double costs[Months];
};

/*second way*/
class Bakery2
{
#ifdef TEST
	public:
#else
	private:
#endif
		static const int Months = 12; // successful
		double costs[Months];
};


int main()
{
	std::cout << Bakery1::Months << std::endl;//shared by all objects
	Bakery1 b1;
	std::cout << b1.Months << std::endl;//object access
	std::cout << Bakery2::Months << std::endl;//shared by all objects
	Bakery2 b2;
	std::cout << b2.Months << std::endl;//object access
	return 0;
}
