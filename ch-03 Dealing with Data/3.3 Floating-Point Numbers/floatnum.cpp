/*Listing 3.8 examines types float and double and how they can differ in the precision
  to which they represent numbers (that’s the significant figure aspect)
 */
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	float tub = 10.0 / 3.0; // good to about 6 places
	double mint = 10.0 / 3.0; // good to about 15 places
	const float million = 1.0e6;
	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nand ten million tubs = ";
	cout << 10 * million * tub << endl;
	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	return 0;
}

/*output:
  tub = 3.333333, a million tubs = 3333333.250000, //not good
  and ten million tubs = 33333332.000000 //not good
  mint = 3.333333 and a million mints = 3333333.333333 // still good
 */
