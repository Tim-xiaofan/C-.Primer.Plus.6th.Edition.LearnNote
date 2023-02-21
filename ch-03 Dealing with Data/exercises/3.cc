#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_DEGREE = 60;

int main(void) 
{
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	
	cout << "First, enter the degrees:";
	double degrees;
	cin >> degrees;
	
	cout << "Next, enter the minutes of arc: ";
	double minutes;
	cin >> minutes;

	cout << "Finally, enter the seconds of arc:";
	double seconds;
	cin >> seconds;

	double result = degrees +  
		seconds / SECONDS_PER_MINUTE/ MINUTES_PER_DEGREE +
		minutes / MINUTES_PER_DEGREE;

	printf("%.0lf degrees, %.0lf minutes, %.0lf seconds = %0.4lf\n",
				degrees, minutes, degrees,
				result);
	return 0;
}

