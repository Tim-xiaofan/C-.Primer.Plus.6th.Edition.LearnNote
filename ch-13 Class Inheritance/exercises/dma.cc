/** 20200214 15:29, zyj, GuangDong, 20230307 15:50*/
// hasDMA.cpp -- impliment
#include "dma.h"
#include <cstring>

// abcDMA methods
abcDMA::abcDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

abcDMA::abcDMA(const abcDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

abcDMA::~abcDMA()
{
	delete [] label;
}

abcDMA & abcDMA::operator=(const abcDMA& rs)
{
	if (this == &rs)
	  return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream& os, const abcDMA& rs)
{
	os << "Label: " << rs.label << 
		", Rating: " << rs.rating;
	return os;
}

//baseDMA methods
baseDMA::baseDMA(const char* l, int r)
		:abcDMA(l, r)
{}

std::ostream & operator<<(std::ostream& os, const baseDMA& rs)
{
	os << (const abcDMA&) rs;
	return os;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
		: abcDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
		: abcDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
		: abcDMA(hs) // invoke abc class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
	  return *this;
	abcDMA::operator=(hs); // copy abc portion
	delete [] style; // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const abcDMA&) hs;
	os << ", Style: " << hs.style;
	return os;
}


// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
		:abcDMA(l, r)
{
	strcpy(color,c);
}

std::ostream & operator<<(std::ostream& os, const lacksDMA& lk)
{
	os << (const abcDMA&) lk;
	os << ", Color: " << lk.color;
	return os;
}
