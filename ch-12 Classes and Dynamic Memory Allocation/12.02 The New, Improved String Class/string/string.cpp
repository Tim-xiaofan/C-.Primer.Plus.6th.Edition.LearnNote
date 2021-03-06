/** 20210131 22:09,zyj,GuangDong*/
// strngbad.cpp -- String class methods
#include <cstring> // string.h for some
#include "string.h"
using std::cout;
// initializing static class member
int String::num_strings = 0;
int String::HowMany()
{
	return num_strings;
}

// class methods
// construct String from C string
String::String(const char * s)
{
	len = std::strlen(s); // set size
	str = new char[len + 1]; // allot storage
	std::strcpy(str, s); // initialize pointer
	num_strings++; // set object count
	cout << num_strings << ": \"" << str
		<< "\" object created\n"; // For Your Information
}

String::String() // default constructor
{
	len = 0;
	str = new char[1];
	str[0] = '\0'; // default string
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\" default object created\n"; // FYI
}

/** bracket operator */
char & String::operator[](int i)
{
	return str[i];
}

// for use with const String objects
const char & String::operator[](int i) const
{
	return str[i];
}

#ifdef DEEP_COPY
String::String(const String & st)
{
	num_strings++; // handle static member update
	len = st.len; // same length
	str = new char [len + 1]; // allot space
	std::strcpy(str, st.str); // copy string to new location
	cout << num_strings << ": \"" << str
		<< "\" object copied\n"; // For Your Information
}

String & String::operator=(const String &st)
{
	if(&st == this)/** object assigned to itself*/
	  return *this;
	delete [] str;/** free old string data*/
	len = st.len;
	str = new char[len + 1]; /** alloc memory for new string*/
	std::strcpy(str, st.str);
	return *this; /** return reference to invoking object*/
}
#endif

String::~String() // necessary destructor
{
	cout << "\"" << str << "\" object deleted, "; // FYI
	--num_strings; // required
	cout << num_strings << " left\n"; // FYI
	delete [] str; // required
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

bool operator<(const String &st1, const String &st2)
{
	if(std::strcmp(st1.str, st2.str) < 0) return true;
	return false;
}

bool operator>(const String &st1, const String &st2)
{
	if(std::strcmp(st1.str, st2.str) > 0) return true;
	return false;
}

bool operator==(const String &st1, const String &st2)
{
	if(std::strcmp(st1.str, st2.str) == 0) return true;
	return false;
}

std::istream & operator>>(std::istream & is, String & st)
{
	is >> st.str;
	st.len = std::strlen(st.str);
	return is;
}
