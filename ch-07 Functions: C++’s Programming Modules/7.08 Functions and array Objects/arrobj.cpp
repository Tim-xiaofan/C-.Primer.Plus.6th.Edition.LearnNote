/*20210105 21:47,zyj,GuangDong*/

//arrobj.cpp -- functions with array objects (C++11)
#include <iostream>
#include <array>
#include <string>
// constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
{"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(std::array<double, Seasons> * pa);

// function that uses array object without modifying it
void show(std::array<double, Seasons> da);

int main(int argc, char *argv[])
{
	std::array<double, Seasons> expenses;
	std::array<int, Seasons> ints;
	std::array<char, Seasons> chars;
	std::string str;
	std::cout << "sizeof(str) = " << sizeof str << std::endl;
	std::cout << "sizeof(Snames) = " << sizeof Snames << std::endl;
	std::cout << "sizeof(expenses) = " << sizeof expenses << std::endl;
	std::cout << "sizeof(ints) = " << sizeof ints << std::endl;
	std::cout << "sizeof(chars) = " << sizeof chars << std::endl;
	fill(&expenses);
	show(expenses);
	return 0;
}
void fill(std::array<double, Seasons> * pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> (*pa)[i];
	} 
}

void show(std::array<double, Seasons> da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
