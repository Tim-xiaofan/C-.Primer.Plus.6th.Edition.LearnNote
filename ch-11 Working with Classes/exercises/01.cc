#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include <fstream>
#include "vect.h"

using std::cout;
using std::endl;
using std::cin;
using VECTOR::Vector;

const char* RESULT_FILE = "result.txt";

int main(void)
{
	srand(time(0)); // seed random-number generator

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps_taken = 0;
	double target;
	double step_len;
	std::ofstream fout(RESULT_FILE);
	if(!fout)
	{
		std::cerr << "could not open file\n";
		return -1;
	}

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> step_len))
		  break;
		fout << "Target Distance: " << target << ", Step Size: " << step_len << endl;
		fout << steps_taken << ": " << result << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(step_len, direction, Vector::POL);
			result = result + step;
			steps_taken++;
			fout << steps_taken << ": " << result << endl;
		}
		fout << "After " << steps_taken << " steps, the subject "
			"has the following location:\n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps_taken << endl;
		steps_taken = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
	  continue;
	return 0;
}
