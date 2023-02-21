#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

const long long SECONDS_PER_MINUTE = 60;
const long long SECONDS_PER_HOUR = 60 * SECONDS_PER_MINUTE;
const long long SECONDS_PER_DAY = SECONDS_PER_HOUR * 24;

int main(void) 
{
	cout << "Enter the number of seconds: " ;
	long long seconds;
	cin >> seconds;

	long long days = seconds / SECONDS_PER_DAY;
	long long remain = seconds % SECONDS_PER_DAY;
	long long hours = remain / SECONDS_PER_HOUR;
	remain %= SECONDS_PER_HOUR;
	long long minutes = remain / SECONDS_PER_MINUTE;
	long long remain_seconds = remain % SECONDS_PER_MINUTE;
	cout << seconds << " seconds = " << days << " days, " << hours << " hours, "
		<< minutes << " minutes, " << remain_seconds << " seconds" << endl;
	return 0;
}

