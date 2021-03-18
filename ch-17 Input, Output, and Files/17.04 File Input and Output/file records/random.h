/* 20210316 21:46, zyj, GuangDong*/
// random.cpp -- query, add, delete, alter records in file
#ifndef RANDOM_H
#define RANDOM_H

#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#include <cstdint> 

#include <sys/stat.h>
/** get file size*/
inline int file_size(const char* filename)
{
    struct stat statbuf;
    stat(filename,&statbuf);
    return statbuf.st_size;
}

#define LIM 20

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
	char name[LIM]; // name of planet
	double population; // its population
	double g; // its acceleration of gravity
};


void random_list(const char *filename, uint32_t place = 0);

int random_query(const char *filename, uint32_t place, struct planet &pl);

int random_insert(const char *filename, int32_t palce, struct planet & pl);

int random_delete(const char *filename, int32_t palce);

int random_alter(const char *filename, int32_t palce, const planet & pl);

#endif
