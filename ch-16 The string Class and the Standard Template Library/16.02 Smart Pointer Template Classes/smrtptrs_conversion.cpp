/* 20210306 14:51, zyj, GuangDong*/
// requires support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;
	shared_ptr<double> pd;
	double *p_reg = new double;
	//pd = p_reg; // not allowed (implicit conversion)
	pd = shared_ptr<double>(p_reg); // allowed (explicit conversion)

	//shared_ptr<double> pshared = p_reg; // not allowed (implicit conversion)
	shared_ptr<double> pshared(p_reg); // allowed (explicit conversion)
}

/** bug: double free */
