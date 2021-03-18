/* 20210316 22:03, zyj, GuangDong*/
// random.cpp -- implement of random.h
#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#include <cstring> // memcpy
#include <unistd.h> // for truncate
#include <sys/types.h>
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

	if(file_size(filename) == 0)
	{
		cout << "empty file\n";
		return;
	}

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
	uint32_t total;
	ifstream fin(filename);

	if(fin.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}

	//cur =fin.tellg();
	//fin.seekg(ios_base::end);
	//total = fin.tellg();
	total =  file_size(filename);
	cout << filename << " is " << total  << " byte"<< endl;
	/** check place*/
	if(place * sizeof(struct planet) >= total)
	{
		cout << "out of flie" << endl;
		fin.close();
		return -1;
	}

	/** set location and read*/
	fin.seekg(place * sizeof(struct planet));
	if(!fin.read((char *) &pl, sizeof(struct planet)))
	{
		cout<< "random_query : read failed";
		fin.close();
		return -1;
	}
	
	fin.close();
	return 0;
	//planet_display(pl);
	//cout << "random_query: reset location to " << cur << endl;

	//if(fin.eof())
	//{
	//	fin.clear(); // clear eof flag
	//	fin.seekg(cur);/** recover filr location*/
	//	return 0; /** reach eof if good*/
	//}

	//if(!fin)
	//{
	//	cerr << "random_query:Error in reading.\n";
	//	exit(EXIT_FAILURE);
	//}
	return 0;
}

int 
random_insert(const char *filename, int32_t place, struct planet & pl)
{
	uint32_t total, ct;
	streampos location;
	fstream finout(filename, ios_base::in | ios_base::out);

	if(finout.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}

	//finout.seekp(0, ios_base::end);
	//total = finout.tellp();
	total = file_size(filename);
	cout << filename << " is " << total  << " byte"<< endl;
	/** check place*/
	if(place < 0) place =0;
	if(place * sizeof(struct planet) >= total)
	{/** append to file end*/
		cout << "random_insert:append to file end" << endl;
		finout.seekp(0, ios_base::end);/** go to the end of the file*/
		//cout << finout.tellp() << endl;
		if(!finout.write((char*) &pl, sizeof(struct planet)))
		{
			finout.close();
			cout << "random_insert: write failed\n";
			return -1;
		}
		finout.close();
	}
	else
	{/** move records between[place, ct] step back and insert*/
		ct = total / sizeof(struct planet);
		//cout << "ct = " << ct << endl;
		//cout << "place = " << place << endl;
		
		/** buffer records from place one to last one */
		int buf_len = (ct - place) * sizeof(planet);
		char *buf = new char[buf_len];
		location = place * sizeof(struct planet);
		finout.seekg(location);
		finout.read(buf, buf_len);
		
		finout.seekp(location);
		//cout << "insert location : " << finout.tellp() << endl;
		finout.write((char *) &pl, sizeof(planet));
		//cout << "after insert: \n";
		//finout.flush();
		//random_list(filename);

		/** rewrite records int buf to file */
		finout.write(buf, buf_len);
		//cout << "after recover: \n";
		finout.flush();
		//random_list(filename);
	}
	return 0;
}

int random_delete(const char *filename, int32_t place)
{
	uint32_t total, ct, buf_len;
	char *buf;
	streampos location;
	fstream finout(filename, ios_base::in | ios_base::out);

	if(finout.is_open() == false)
	{
		cout << "file is not open" << endl;
		return -1;
	}
	total = file_size(filename);
	cout << filename << " is " << total  << " byte."<< endl;
	ct = total / sizeof(planet);
	cout << "There are " << ct  << " records." << endl;

	/** check place*/
	if(place < 0 || (uint32_t)place >= ct)
	{
		cout << "invalid place " 
			<< place << endl;
		return -1;
	}

	/** read and move */
	buf_len = (ct - place - 1) * sizeof(planet);
	if(buf_len == 0)
	{/** rm last record, just truncate*/
		truncate(filename, total - sizeof(planet));
		//cout << "after truncate, file is " 
		//	<< file_size(filename) << " bytes\n";
	}
	else
	{
		/** FIXME: we need to do something when file size is huge*/
		buf = new char[buf_len];
		/** buffer record behind place in buf*/
		location = (place + 1) * sizeof(planet);
		finout.seekg(location);
		//cout << "read location is " << finout.tellg() << endl;
		finout.read(buf, buf_len);
		/** truncate file */
		truncate(filename, total - sizeof(planet) - buf_len);
		//cout << "after truncate, file is " 
		//	<< file_size(filename) << " bytes\n";
		/** rewrite records in buf*/
		location = place * sizeof(planet);
		finout.seekp(location);
		//cout << "write location is " << finout.tellp() << endl;
		finout.write(buf, buf_len);
		finout.flush();
	}
	return 0;
}

int random_alter(const char *filename, int32_t palce)
{
	return -1;
}


int main()
{
	using namespace std;
	
	planet pl;
	int place;
	
	cout << fixed << right;

	cout << "origin content : \n";
	random_list(file);
	//if(random_query(file, 4, pl) == 0)
	//{
	//	cout << "4 recover : \n";
	//	planet_display(pl);
	//}

	//cout << "enter the planet' name : ";
	//cin.get(pl.name, LIM);
	//eatline();
	//cout << "enter the planet's population : ";
	//cin >> pl.population;
	//eatline();
	//cout << "enter the planet's gravity : ";
	//cin >> pl.g;
	//eatline();
	//cout << "enter place to insert:";
	//cin >> place;
	//eatline();
	//random_insert(file, place, pl);
	//
	//cout << "after insert : \n";
	//random_list(file);

	cout << "select record to delete:";
	cin >> place;
	eatline();
	random_delete(file, place);
	cout << "after delete : \n";
	random_list(file);
}
