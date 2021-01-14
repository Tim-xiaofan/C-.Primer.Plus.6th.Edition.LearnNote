/*20210114 13:00,zyj,GuangDong*/
// left.cpp -- string function with a default argument
#include <iostream>
#include <cstring>
const int ArSize = 80;
char * left(const char * str, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Enter a string:\n";
	cin.get(sample,ArSize);
	char *ps = left(sample, 4);
	cout << ps << endl;
	delete [] ps; // free old string
	ps = left(sample);
	cout << ps << endl;
	delete [] ps; // free new string'
	return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char * left(const char * str, int n)
{
	int len = strlen(str);
	n = (n < len) ? n : len;
	char *p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++)//min(n, strlen)
	  p[i] = str[i]; // copy characters
	while (i <= n)
	  p[i++] = '\0'; // set rest of string to '\0'
	return p;
}
