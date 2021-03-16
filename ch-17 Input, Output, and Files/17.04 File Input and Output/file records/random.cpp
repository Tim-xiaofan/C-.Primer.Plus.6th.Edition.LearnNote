/* 20210316 22:03, zyj, GuangDong*/
// random.cpp -- implement of random.h
#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#include "random.h"

using namespace std;

void planet_display(const struct planet & pl)
{
	cout << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
}

void 
random_list(std::fstream & fin, uint32_t place)
{
	uint32_t cur, ct;

	if(fin.is_open() == false)
	{
		cout << "file is not open" << endl;
		return;
	}

	cur = fin.tellg();
	fin.seekg(place * sizeof(struct planet));

	struct planet pl;
	cout << fixed << right;

	ct = 0;
	while(fin.read((char *) &pl, sizeof(struct planet)))
	{
		cout << ct++ << ": ";
		planet_display(pl);
	}

	if(fin.eof())
	{
		fin.clear(); // clear eof flag
		fin.seekg(cur);/** recover filr location*/
	}
	else
	{
		cerr << "random_list:Error in reading.\n";
		exit(EXIT_FAILURE);
	}
}

int 
random_query(std::fstream & fin, uint32_t place, struct planet &pl)
{
	uint32_t cur, total;

	if(fin.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}

	cur =fin.tellg();
	fin.seekg(ios_base::end);
	total = fin.tellg();
	/** check place*/
	if(place * sizeof(struct planet) >= total)
	{
		cout << "out of flie" << endl;
		return -1;
	}

	fin.read((char *) &pl, sizeof(struct planet));
	if(fin.eof())
	{
		fin.clear(); // clear eof flag
		fin.seekg(cur);/** recover filr location*/
	}
	return 0;
}

int random_insert(std::ofstream & fout, uint32_t palce)
{
	return -1;
}

int random_delete(std::ofstream & fout, uint32_t palce)
{
	return -1;
}

int random_alter(std::fstream & fout, uint32_t palce)
{
	return -1;
}


int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

	fstream finout; // read and write streams
	finout.open(file,ios::in | ios::out |ios::binary);

	random_list(finout);
	random_query(finout, 0, pl);
	cout << "0 recover : ";
	planet_display(pl);
}
