/** 20210131 22:09,zyj,GuangDong*/
// string.h -- improved string class definition
#include <iostream>
#ifndef STRING_H_
#define STRING_H_
#define DEEP_COPY
class String
{
	private:
		char * str; // pointer to string
		int len; // length of string
		static int num_strings; // number of objects
		static const int CINLIM = 80; // cin input limit
	public:
		String(const char * s); // constructor
		String(); // default constructor
		~String(); // destructor
		int length () const { return len; }
		char & operator[](int i);
		const char & operator[](int i) const;
		static int HowMany();
#ifdef DEEP_COPY
		String(const String &st);
		String & operator=(const String &st);
		String & operator=(const char *);
		String & operator=(char);
		String & operator=(int);
#endif
		// friend function
		friend std::ostream & operator<<(std::ostream & os,
					const String & st);
		friend bool operator<(const String &st, const String &st2);
		friend bool operator>(const String &st1, const String &st2);
		friend bool operator==(const String &st, const String &st2);
		friend std::istream & operator>>(std::istream & is, String & st);
};
#endif
