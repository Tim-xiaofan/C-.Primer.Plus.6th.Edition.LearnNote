/*20210127 22:21,zyj,GuangDong*/
// mytime1.cpp -- implementing Time methods
#include <iostream>
#include "mytime1.h"
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m )
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
	//std::cout << "h = " << h << ","
	//	<< "m = " << m <<std::endl;
}

Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator-(const Time & t) const
{
	Time delt(0, 0);
	int tmpHours = hours, tmpMimites = minutes;

	if((*this) <= t)
	  return delt;
	if(t.minutes > minutes)
	{
		tmpHours -= 1;
		tmpMimites += 60;
	}
	tmpHours -= t.hours;
	tmpMimites -= t.minutes;
	//std::cout << "tmpHours = " << tmpHours << ","
	//	<< "tmpMimites = " << tmpMimites << std:: endl;
	delt.Reset(tmpHours, tmpMimites);
	return delt;
}

Time Time::operator*(double mult) const
{
	int m_minutes = minutes, m_hours = hours;
	m_minutes *= mult;
	m_hours *= mult;
	m_hours += m_minutes/60;
	m_minutes %= 60;
	return Time(m_hours, m_minutes);
}

void Time::Show() const
{
	std::cout << "("<< hours << " hours, " << minutes << " minutes)";
}

bool Time::operator>(const Time & t) const
{
	if((hours * 60 + minutes) > (t.hours * 60 + t.minutes))
	  return true;
	else return false;
}

bool Time::operator<(const Time & t) const
{
	if((hours * 60 + minutes) < (t.hours * 60 + t.minutes))
	  return true;
	else return false;
}

bool Time::operator>=(const Time & t) const
{
	if((hours * 60 + minutes) >= (t.hours * 60 + t.minutes))
	  return true;
	else return false;
}

bool Time::operator<=(const Time & t) const
{
	if((hours * 60 + minutes) <= (t.hours * 60 + t.minutes))
	  return true;
	else return false;
}

bool Time::operator=(const Time & t) const
{
	if((hours * 60 + minutes) == (t.hours * 60 + t.minutes))
	  return true;
	else return false;
}


#ifdef FRIEND
Time operator*(double mult, const Time &t) /** friend not used in definition*/
{
	int m_minutes = t.minutes, m_hours = t.hours;
	m_minutes *= mult;
	m_hours *= mult;
	m_hours += m_minutes/60;
	m_minutes %= 60;
	return Time(m_hours, m_minutes);
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
	os << "("<< t.hours << " hours, " << t.minutes << "minutes)";
	return os;
}
#endif
