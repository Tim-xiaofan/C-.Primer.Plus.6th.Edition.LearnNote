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
random_list(const char *filename, uint32_t place)
{
	uint32_t cur, ct;
	ifstream fin(filename);

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
		//cout << "random_list: reset location to " << cur << endl;
	}
	else
	{
		cerr << "random_list:Error in reading.\n";
		exit(EXIT_FAILURE);
	}
}

int 
random_query(const char *filename, uint32_t place, struct planet &pl)
{
	uint32_t cur, total;
	ifstream fin(filename);

	if(fin.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}

	cur =fin.tellg();
	//fin.seekg(ios_base::end);
	//total = fin.tellg();
	total =  file_size(filename);
	cout << filename << " is " << total  << " byte"<< endl;
	/** check place*/
	if(place * sizeof(struct planet) >= total)
	{
		cout << "out of flie" << endl;
		return -1;
	}

	/** set location and read*/
	fin.seekg(place * sizeof(struct planet));
	if(!fin.read((char *) &pl, sizeof(struct planet)))
	{
		cout<< "random_query : read failed";
	}
	//planet_display(pl);
	//cout << "random_query: reset location to " << cur << endl;

	if(fin.eof())
	{
		fin.clear(); // clear eof flag
		fin.seekg(cur);/** recover filr location*/
		return 0; /** reach eof if good*/
	}

	if(!fin)
	{
		cerr << "random_query:Error in reading.\n";
		exit(EXIT_FAILURE);
	}
	return 0;
}

int 
random_insert(const char *filename, uint32_t place, struct planet & pl)
{
	uint32_t cur, total;
	ofstream fout(filename, ios_base::app);

	if(fout.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}

	cur =fout.tellp();
	fout.seekp(ios_base::end);
	total = fout.tellp();
	/** check place*/
	if(place * sizeof(struct planet) >= total)
	{
		cout << "random_insert:out of flie" << endl;
		return -1;
	}
	return -1;
}

int random_delete(const char *filename, uint32_t palce)
{
	return -1;
}

int random_alter(const char *filename, uint32_t palce)
{
	return -1;
}


int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

	fstream finout; // read and write streams
	finout.open(file, ios::in | ios::out |ios::binary);

	random_list(file);
	random_query(file, 4, pl);
	cout << "0 recover : \n";
	planet_display(pl);

	random_insert(file, 0, pl);
}
