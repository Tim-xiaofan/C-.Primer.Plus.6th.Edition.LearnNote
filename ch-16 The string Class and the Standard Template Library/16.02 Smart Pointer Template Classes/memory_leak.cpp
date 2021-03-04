/* 20210304 21:52, zyj, GuangDong*/
// memory_leak.cpp
#include <iostream>
#include <string>
#include <signal.h>

bool force_quit = false;

void remodel(std::string & str)
{
	std::string * ps = new std::string(str);
	str = *ps;
	return;
}

void handle(int signum)
{
	if(signum == SIGINT)
	{
		std::cout << "Bye...\n";
		force_quit = true;
	}
}

int main()
{
	using namespace std;
	signal(SIGINT, handle);
	string str;
	while(!force_quit)
	  remodel(str);
}
