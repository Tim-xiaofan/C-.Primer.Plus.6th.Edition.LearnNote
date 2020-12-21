/*20201221 21:06,zyj,GuangDong*/
// delete_usage.cpp
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	int * ps = new int; // ok
	delete ps; // ok
	//delete ps; // not ok now
	int jugs = 5; // ok
	int * pi = &jugs; // ok
	//delete pi; // not allowed, memory not allocated by new
	char *pc = new(char);
	delete(pc);
	pc == NULL;
	delete(pc);/*delete is safe to applydelete to a null pointer.*/
	int * pi1 = new int; // allocate memory
	int * pi2 = pi1; // set second pointer to same block
	delete pi2; // delete with second pointer
	delete pi; //error:twice
	return 0;
}
