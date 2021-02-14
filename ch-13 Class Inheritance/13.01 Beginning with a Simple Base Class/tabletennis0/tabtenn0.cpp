/** 20210210 15:46, zyj, GuangDong */
//tabtenn0.cpp -- simple base-class methods
#include "tabtenn0.h"
#include <iostream>
TableTennisPlayer::TableTennisPlayer (const string & fn,
			const string & ln, bool ht) : firstname(fn), 
	lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

/** use constructor*/
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
			const string & ln, bool ht) : 
	TableTennisPlayer(fn, ln, ht), rating(r)
{
}

/** use implicit copy constructor*/
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
		: TableTennisPlayer(tp)
{
	rating = r;
}
