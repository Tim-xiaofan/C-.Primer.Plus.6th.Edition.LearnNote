#include "complex0.h"

complex0::complex0(double r, double i)
		:real_(r),
		imaginary_(i)
{}

complex0 complex0::operator+(const complex0& c)
{
	return complex0(real_ + c.real_, imaginary_ + c.imaginary_);
}

complex0 complex0::operator-(const complex0& c)
{
	return complex0(real_ - c.real_, imaginary_ - c.imaginary_);
}

complex0 complex0::operator*(const complex0& c)
{
	return complex0(real_ * c.real_ - imaginary_ * c.imaginary_,
				real_ * c.imaginary_ + imaginary_ * c.real_);
}

complex0 complex0::operator*(double d)
{
	return complex0(real_ * d, imaginary_ * d);
}

complex0 operator*(double d, const complex0& c)
{
	return complex0(c.real_ * d,  c.imaginary_ * d);
}

complex0 complex0::operator~(void)
{
	return complex0(-real_, -imaginary_);
}

std::ostream& operator<<(std::ostream& os, const complex0& c)
{
	os << c.real_;
	if(c.imaginary_ > 0)
	{
		os << '+' << c.imaginary_ << 'i';
	}
	else if(c.imaginary_ < 0)
	{
		os << c.imaginary_ << 'i';
	}
	return os;
}

std::istream& operator>>(std::istream& is, complex0& c)
{
	is >> c.real_;
	is >> c.imaginary_;
	return is;
}
