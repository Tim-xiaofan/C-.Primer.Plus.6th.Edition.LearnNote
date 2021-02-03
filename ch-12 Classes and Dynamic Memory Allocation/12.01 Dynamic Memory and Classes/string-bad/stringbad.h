/** 20210131 16:24,zyj,GuangDong*/
// strngbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
#define DEEP_COPY
class StringBad
{
	private:
		char * str; // pointer to string
		int len; // length of string
		static int num_strings; // number of objects
	public:
		StringBad(const char * s); // constructor
		StringBad(); // default constructor
		~StringBad(); // destructor
#ifdef DEEP_COPY
		StringBad(const StringBad &st);
#endif
		// friend function
		friend std::ostream & operator<<(std::ostream & os,
					const StringBad & st);
};
#endif
