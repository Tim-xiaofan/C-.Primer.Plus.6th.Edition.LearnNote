// string1.cpp -- String class methods
#include <cstring> // string.h for some
#include <cctype>
#include <algorithm>
#include "string1.h" // includes <iostream>

using std::cin;
using std::cout;
// initializing static class member
int String::num_strings = 0;
// static method
int String::HowMany()
{
	return num_strings;
}

// class methods
String::String(const char * s) // construct String from C string
{
	len = std::strlen(s); // set size
	str = new char[len + 1]; // allot storage
	std::strcpy(str, s); // initialize pointer
	num_strings++; // set object count
}

String::String() // default constructor
{
	len = 4;
	str = new char[1];
	str[0] = '\0'; // default string
	num_strings++;
}

String::String(const String & st)
{
	num_strings++; // handle static member update
	len = st.len; // same length
	str = new char [len + 1]; // allot space
	std::strcpy(str, st.str); // copy string to new location
}

String::~String() // necessary destructor
{
	--num_strings; // required
	delete [] str; // required
}

String & String::operator=(const String & st)
{
	if (this == &st)
	  return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// assign a C string to a String
String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// read-write char access for non-const String
char & String::operator[](int i)
{
	return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
	return str[i];
}

String String::operator+(const String& rhs) const
{
	char* tmp = new char[len + rhs.len + 1];
	memset(tmp, 0, len + rhs.len + 1);
	strcat(tmp, str);
	strcat(tmp, rhs.str);
	String ret(tmp);
	delete[] tmp;
	return ret;
}

String& String::stringlow(void)
{
	String& ret = *this;
	auto tolower = [](char& ch)
	{ if(::isupper(ch)) { ch = ::tolower(ch);} };
	std::for_each(ret.str, ret.str + ret.len, tolower);
	return ret;
}

String& String::stringup(void)
{
	String& ret = *this;
	auto toupper = [](char& ch)
	{ if(::islower(ch)) { ch = ::toupper(ch);} };
	std::for_each(ret.str, ret.str + ret.len, toupper);
	return ret;
}

int String::has(char ch) const
{
	return std::count_if(str, str + len, [ch](char x){ return ch == x; });
}

// overloaded operator friends
bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}


// simple String output
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

// quick and dirty String input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	  st = temp;
	while (is && is.get() != '\n')
	  continue;
	return is;
}
