/*20201218 23:01,zyj,GUANGDONG*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct torgle_register
{
	unsigned int SN : 4; // 4 bits for SN value
	unsigned int : 4; // 4 bits unused
	bool goodIn : 1; // valid input (1 bit)
	bool goodTorgle : 1; // successful torgling
};
int main(int argc, char *argv[])
{
	struct torgle_register tr{14, true, false};
	cout << "sizeof(torgle_register) = " << sizeof(struct torgle_register) << endl;
	//printf("%p\n%p\n%p", &tr.SN, &tr.goodIn, &tr.goodTorgle);/* error:attempt to take address of bit-field*/
	return 0;
}

/*
output:
   sizeof(torgle_register) = 4
 */
