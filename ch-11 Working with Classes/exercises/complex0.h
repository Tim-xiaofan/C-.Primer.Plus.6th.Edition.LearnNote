#ifndef _COMPLEX0_H_
#define _COMPLEX0_H_

#include <iostream>

class complex0
{
	public:
		complex0(double r = 0.0, double i = 0.0);
		complex0 operator+(const complex0& c);
		complex0 operator-(const complex0& c);
		complex0 operator*(const complex0& c);
		complex0 operator*(double d);
		friend complex0 operator*(double d, const complex0& c);
		complex0 operator~(void);

		friend std::ostream& operator<<(std::ostream&, const complex0&);
		friend std::istream& operator>>(std::istream&, complex0&);
	private:
		double real_;
		double imaginary_;
};

#endif
