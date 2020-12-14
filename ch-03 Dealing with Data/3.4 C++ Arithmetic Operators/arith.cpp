/*
 * arith.cpp
 */
#include <iostream>
int main()
{
	using namespace std;
	float hats, heads;
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	cout << "Enter a number: ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;
	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;
	return 0;
}

/*
   Enter a number: 50.25
   Enter another number: 11.17
   hats = 50.250000; heads = 11.170000
   hats + heads = 61.419998 //not good
   hats - heads = 39.080002 //not good
   hats * heads = 561.292480
   hats / heads = 4.498657
 */
