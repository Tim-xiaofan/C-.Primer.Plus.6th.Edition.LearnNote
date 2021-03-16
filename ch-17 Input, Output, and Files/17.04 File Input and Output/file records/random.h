/* 20210316 21:46, zyj, GuangDong*/
// random.cpp -- query, add, delete, alter records in file
#ifndef RANDOM_H
#define RANDOM_H

#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#include <cstdint> 

#define LIM 20

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
	char name[LIM]; // name of planet
	double population; // its population
	double g; // its acceleration of gravity
};

const char * file = "planets.dat";

void random_list(std::fstream & fin, uint32_t place = 0);

int random_query(std::fstream & fin, uint32_t place, struct planet &pl);

int random_insert(std::ofstream & out, uint32_t palce);

int random_delete(std::ofstream & out, uint32_t palce);

int random_alter(std::ofstream & out, uint32_t palce);

#endif
