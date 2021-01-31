/** 20210130 17:10,zyj,GunagDong*/
// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	//static int count = 1;
	//cout << "#" << count++ << " Stonewt::Stonewt(double lbs)" << std::endl;
	stone = int (lbs) / Lbs_per_stn; // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

#ifdef AMBIGUOUS
// construct Stonewt object from int value
Stonewt::Stonewt(long lbs)
{
	static int count = 1;
	cout << "#" << count++ << " Stonewt::Stonewt(long lbs)" << std::endl;
	stone = int (lbs) / Lbs_per_stn; // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}
#endif

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt() // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() // destructor
{}

// show weight in stones
void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

#define LOG 1
/** conversion functions*/
Stonewt::operator long() const
{
#ifdef LOG
	cout << "\"operator long() const\" is excuted\n";
#endif
	return pounds + 0.5;
}

Stonewt::operator int() const
{
#ifdef LOG
	cout << "\"operator int() const\" is excuted\n";
#endif
	return pounds + 0.5;
}

Stonewt::operator double() const
{
#ifdef LOG
	cout << "\"operator double() const\" is excuted\n";
#endif
	return pounds;
}
