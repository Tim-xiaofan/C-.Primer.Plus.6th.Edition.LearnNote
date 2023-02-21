#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

int main(void) 
{
	cout << "Enter the world's population: ";
	long long world_population;
	cin >> world_population;

	cout << "Enter the population of the US: ";
	long long USA_population;
	cin >> USA_population;
	double percent = double(USA_population) / world_population * 100;

	cout.precision(7);
	cout << "The population of the US is "<< percent <<"% of the world population."<<endl;
	return 0;
}

