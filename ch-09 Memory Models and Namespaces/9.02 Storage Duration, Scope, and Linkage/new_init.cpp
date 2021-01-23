/*20210121 20:59,zyj,GuangDong*/
// new_init.cpp
#include <iostream>
using namespace std;
int main()
{
	int *pi = new int (6); // *pi set to 6
	double * pd = new double (99.99); // *pd set to 99.99
	struct where {double x; double y; double z;};
	where * one = new where {2.5, 5.3, 7.2}; // C++11
	int * ar = new int [4] {2,4,6,7}; // C++11
	int *pin = new int {6}; // *pi set to 6
	double * pdo = new double {99.99}; // *pd set to 99.99
	return 0;
}
