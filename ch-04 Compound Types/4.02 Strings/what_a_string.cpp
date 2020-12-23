//what a string
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'}; // not a string!
	char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'}; // a string!
	cout << "cat:" << cat << endl;
	cout << "dog:" << dog << endl;
	printf("cat:%s\n", cat);
	printf("dog:%s\n", dog);
}

/*
   catfatessa
   dogbeaux IIfatessaux IIfatessa
   catfatessa
   dogbeaux IIfatessaux IIfatessa
 */
