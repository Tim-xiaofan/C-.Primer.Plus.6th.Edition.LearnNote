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

const char * file = "planets.dat";

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
	
	cout << "enter the planet' name : ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "enter the planet's population : ";
	cin >> pl.population;
	eatline();
	cout << "enter the planet's gravity : ";
	cin >> pl.g;
	eatline();
	cout << "enter place to alter:";
	cin >> place;
	eatline();
	random_alter(file, place, pl);
	cout << "after alter : \n";
	random_list(file);
}
