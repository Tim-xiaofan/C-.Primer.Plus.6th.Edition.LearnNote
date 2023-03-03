#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include <fstream>
#include "vect.h"

using std::cout;
using std::endl;
using std::cin;
using VECTOR::Vector;

int main(void)
{
	srand(time(0)); // seed random-number generator

	double direction;
	Vector step;

	double target;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		double step_len;
		cout << "Enter step length: ";
		if (!(cin >> step_len))
		  break;
		int times = 0;
		cout << "times to try: ";
		if(!(cin >> times))
		{
			break;
		}
		unsigned long steps_taken = 0;
		unsigned sum_steps = 0;
		unsigned long min_steps = 0;
		unsigned long max_steps = 0;
		for(int i = 0; i < times; ++i)
		{
			Vector result(0.0, 0.0);
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(step_len, direction, Vector::POL);
				result = result + step;
				steps_taken++;
			}
			if(i > 0)
			{
				if(min_steps > steps_taken)
				{
					min_steps = steps_taken;
				}
				if(max_steps < steps_taken)
				{
					max_steps =  steps_taken;
				}
			}
			else
			{
				min_steps = steps_taken;
				max_steps = steps_taken;
			}
			sum_steps+= steps_taken;
		}
		cout << "for " << times << " trials----->\n";
		cout << "min: " << min_steps << endl;
		cout << "max: " << max_steps << endl;
		cout << "average: " << static_cast<double>(sum_steps) / times << endl;
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
	  continue;
	return 0;
}
